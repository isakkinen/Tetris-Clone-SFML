#include "TetrisScreen.h"
#include <iostream>
#include <thread>
TetrisScreen::TetrisScreen(const sf::Vector2f & position,
	const sf::Vector2f& blockSize)
{
	// Initialize the backround
	background.setFillColor(backgroundColor);
	background.setSize({ (blockSize.x + borderWidth)*(width)+borderWidth,(blockSize.y + borderHeight)*(height)+borderHeight });
	background.setPosition({ position.x - borderWidth, position.y - borderHeight });
	// Initialize the gameBoard
	for (unsigned iY = 0; iY < height; ++iY) {
		for (unsigned iX = 0; iX < width; ++iX) {
			gameBoard[iY][iX] = (Block({ position.x + (blockSize.x + borderWidth)*iX,
										position.y + (blockSize.y + borderHeight)*iY },
										blockSize));
		}
	}
	// Set initial tetromino
	currentTetromino = &Tetromino::iTetromino;
}

void TetrisScreen::update(const float dt)
{
	// Update the inputState
	inputState->update(dt);
	// Delay update until timer is set
	while (updateTimer >= updateDelay) {
		updateTimer -= updateDelay;
		// Move the currentTetromino down by one
		if (canMove({ 0,1 })) {
			moveTetromino({ 0,1 });
		}
		else {
			plantTetromino();
			newTetromino();
		}
	}

	// Update every block one by one
	for (auto& row : gameBoard) {
		for (auto& block : row) {
			block.update(dt);
		}
	}

	// Scan lines
	scanLines();
	// Update the timer
	advanceTimer(dt);

}

void TetrisScreen::handleInput()
{
	inputState->handleInput(this);
}

void TetrisScreen::setInputState(PlayInputState & state)
{
	inputState = &state;
}

void TetrisScreen::advanceTimer(const float dt)
{
	updateTimer += dt;
}

void TetrisScreen::resetTimer()
{
	updateTimer = 0.0f;
}

void TetrisScreen::skipStep()
{
	updateTimer = updateDelay;
}

void TetrisScreen::drawTetromino()
	// Draw the currentTetromino in the correct position (and ignore out of bounds pixels)
{
	const std::vector<std::vector<bool>> shape{ currentTetromino->getShape(tetrominoAngle) };
	for (int iY = 0; iY < 4; ++iY) {
		for (int iX = 0; iX < 4; ++iX) {
			bool isOutX{ iX + tetrominoPosition.x < 0 || iX + tetrominoPosition.x >= width };
			bool isOutY{ iY + tetrominoPosition.y < 0 || iY + tetrominoPosition.y >= height };
			if (!isOutX && !isOutY) {
				Block& target{ gameBoard[tetrominoPosition.y + iY][tetrominoPosition.x + iX] };
				if (shape[iY][iX]) {
					target.setColor(currentTetromino->getColor());
				}
				else if(!target.isPlanted()){
					target.setColor(boardColor);
				}
			}
		}
	}
}

void TetrisScreen::newTetromino()
{

	tetrominoPosition = { spawnPosition };

	const int nextTetromino = uni(rng);

	switch (nextTetromino)
	{
	case 0:
		currentTetromino = &Tetromino::oTetromino;
		break;
	case 1:
		currentTetromino = &Tetromino::iTetromino;
		break;
	case 2:
		currentTetromino = &Tetromino::sTetromino;
		break;
	case 3:
		currentTetromino = &Tetromino::zTetromino;
		break;
	case 4:
		currentTetromino = &Tetromino::jTetromino;
		break;
	case 5:
		currentTetromino = &Tetromino::lTetromino;
		break;
	case 6:
		currentTetromino = &Tetromino::tTetromino;
		break;
	}
	tetrominoAngle = Angle::North;
	clearScreen();
	drawTetromino();
}

void TetrisScreen::plantTetromino()
	// Marks the tetromino as fallen, static, you know?
{
	for (int iY = 0; iY < 4; ++iY) {
		for (int iX = 0; iX < 4; ++iX) {
			if (currentTetromino->getShape(tetrominoAngle)[iY][iX]) {
				const int blockX{ tetrominoPosition.x + iX };
				const int blockY{ tetrominoPosition.y + iY };
				gameBoard[blockY][blockX].plant();
			}
		}
	}
}

void TetrisScreen::rotateTetromino(const RotationDirection direction)
{
	if (!canRotate(direction)) return;
	switch (direction)
	{
	case RotationDirection::Clockwise:
		tetrominoAngle = static_cast<Angle>(tetrominoAngle + 1 > 3 ? 0 : tetrominoAngle + 1);
		break;
	case RotationDirection::CounterClockwise:
		tetrominoAngle = static_cast<Angle>(tetrominoAngle - 1 < 0 ? 3 : tetrominoAngle - 1);
		break;
	}
	clearScreen();
	drawTetromino();
}

void TetrisScreen::moveTetromino(const sf::Vector2i & dir)
	// Checks if tetromino can move and then does so if allowed
{
	if (canMove(dir)) {
		tetrominoPosition += dir;
		clearScreen();
		drawTetromino();
	}
}

void TetrisScreen::dropTetromino()
	// Makes the tetromino fall straight down instantaniously
{
	for (int i = 0; i < height; ++i) {
		if (canMove({ 0,1 })) {
			moveTetromino({ 0,1 });
		}
		else {
			plantTetromino();
			newTetromino();
			resetTimer();
			break;
		}
	}
}

bool TetrisScreen::canMove(const sf::Vector2i & dir)
{
	for (int iY = 0; iY < 4; ++iY) {
		for (int iX = 0; iX < 4; ++iX) {
			bool isOutX{ iX + tetrominoPosition.x < 0 ||
						iX + tetrominoPosition.x >= width };
			bool isOutY{ iY + tetrominoPosition.y < 0 ||
						iY + tetrominoPosition.y >= height };
			// If the checked block is already out of bounds, don't bother to check
			if (isOutX || isOutY) continue;

			bool isBlock{ currentTetromino->getShape(tetrominoAngle)[iY][iX] == true };
			int targetX{ tetrominoPosition.x + iX + dir.x };
			int targetY{ tetrominoPosition.y + iY + dir.y };

			// If at the checked coordinate there is a piece of currentTetromino, check collision
			if (!isBlock) continue;
			// If we are trying to go out of bounds, return false
			if (targetX < 0 ||
				targetX >= width ||
				targetY >= height) {
				return false;
			}
			// If there is already a block, return false
			else if (gameBoard[targetY][targetX].isPlanted()) {
				return false;
			}
		}
	}
	// Otherwise we're good to go
	return true;
}

bool TetrisScreen::canRotate(const RotationDirection direction)
{
	Angle potentialAngle = tetrominoAngle;
	switch (direction)
	{
	case RotationDirection::Clockwise:
		potentialAngle = static_cast<Angle>(tetrominoAngle + 1 > 3 ? 0 : tetrominoAngle + 1);
		break;
	case RotationDirection::CounterClockwise:
		potentialAngle = static_cast<Angle>(tetrominoAngle - 1 < 0 ? 3 : tetrominoAngle - 1);
		break;
	}

	for (int iY = 0; iY < 4; ++iY) {
		for (int iX = 0; iX < 4; ++iX) {
			bool isOutX{ iX + tetrominoPosition.x < 0 ||
				iX + tetrominoPosition.x >= width };
			bool isOutY{ iY + tetrominoPosition.y < 0 ||
				iY + tetrominoPosition.y >= height };
			// If the checked block is already out of bounds, don't bother to check

			bool isBlock{ currentTetromino->getShape(potentialAngle)[iY][iX] == true };
			int targetX{ tetrominoPosition.x + iX };
			int targetY{ tetrominoPosition.y + iY };

			// If at the checked coordinate there is a piece of currentTetromino, check collision
			if (!isBlock) continue;
			// If we are trying to rotate out of bounds, move the tetromino away
			while (targetX < 0) {
				moveTetromino({ 1,0 });
				++targetX;
			}
			while (targetX >= width) {
				moveTetromino({ -1,0 });
				--targetX;
			}

			if (targetX < 0 ||
				targetX >= width ||
				targetY >= height) {
				return false;
			}
			// If there is already a block, return false
			else if (gameBoard[targetY][targetX].isPlanted()) {
				return false;
			}
		}
	}
	
	return true;
}

void TetrisScreen::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	// Draw backround
	target.draw(background);
	// Draw every block one by one
	for (const auto& row : gameBoard) {
		for (const auto& block : row) {
			target.draw(block);
		}
	}
}

void TetrisScreen::clearScreen()
	// Clears the gameBoard from previous frame junk
{
	for (unsigned iY = 0; iY < height; ++iY) {
		for (unsigned iX = 0; iX < width; ++iX) {
			if (!gameBoard[iY][iX].isPlanted()) {
				gameBoard[iY][iX].setColor(boardColor);
			}
		}
	}
}

void TetrisScreen::scanLines()
{
	for (unsigned iY = 0; iY < height; ++iY) {
		for (unsigned iX = 0; iX < width; ++iX) {
			// If one of the blocks is empty, ignore the rest of the line and continue to the next
			if (!gameBoard[iY][iX].isPlanted()) {
				break;
			}
			// Otherwise if every block in current y-coordinate is planted, we destroy the line
			else if (iX == width-1) {
				std::cout << "EXTERMINATE\n";
				destroyLine(iY);
				break;
			}
		}
	}
}

void TetrisScreen::destroyLine(const unsigned y)
{
	for (int iX = 0; iX < width; ++iX) {
		// Go from down to up and pull every block down by one
		for (int iY = y; iY > 1; --iY) {
			// Copy the attributes from block above the target block
			auto& target{ gameBoard[iY][iX] };
			target.setColor(gameBoard[iY - 1][iX].getColor());
			if (!gameBoard[iY - 1][iX].isPlanted()) {
				target.unplant();
			}
			else {
				target.plant();
			}
		}
	}
}
