#include "InputState.h"
#include "TetrisScreen.h"



void Idle::handleInput(TetrisScreen * target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		target->moveTetromino({ -1,0 });
		target->setInputState(PlayInputState::leftPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		target->moveTetromino({ 1,0 });
		target->setInputState(PlayInputState::rightPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		target->setInputState(PlayInputState::downPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		target->rotateTetromino(RotationDirection::CounterClockwise);
		target->setInputState(PlayInputState::cRotationPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		target->rotateTetromino(RotationDirection::Clockwise);
		target->setInputState(PlayInputState::rotationPressed);
	}
}

void PlayInputState::update(const float dt)
{
}

void LeftPressed::handleInput(TetrisScreen * target)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		target->setInputState(PlayInputState::idle);
	}
}

void RightPressed::handleInput(TetrisScreen * target)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		target->setInputState(PlayInputState::idle);
	}
}

void DownPressed::handleInput(TetrisScreen * target)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		isPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isPressed && !doubleTapped) {
		target->dropTetromino();
		doubleTapped = true;
	}
	if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || doubleTapped) && updateTimer >= updateDelay) {
		// Reset all values and return the state to idle
		updateTimer = 0.0f;
		isPressed = true;
		doubleTapped = false;
		target->setInputState(PlayInputState::idle);
	}
}

void DownPressed::update(const float dt)
{
	updateTimer += dt;
}

void RotationPressed::handleInput(TetrisScreen * target)
{
	//target->rotateTetromino(RotationDirection::Clockwise);
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		target->setInputState(PlayInputState::idle);
	}
}

void CRotationPressed::handleInput(TetrisScreen * target)
{
	//target->rotateTetromino(RotationDirection::CounterClockwise);
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		target->setInputState(PlayInputState::idle);
	}
}

Idle PlayInputState::idle;
LeftPressed PlayInputState::leftPressed;
RightPressed PlayInputState::rightPressed;
DownPressed PlayInputState::downPressed;
RotationPressed PlayInputState::rotationPressed;
CRotationPressed PlayInputState::cRotationPressed;