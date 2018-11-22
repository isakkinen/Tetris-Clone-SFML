#include "InputState.h"
#include "TetrisScreen.h"

void LeftPressed::handleInput(TetrisScreen * target)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		target->setInputState(*new Idle);
	}
}

void RightPressed::handleInput(TetrisScreen * target)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		target->setInputState(*new Idle);
	}
}

void Idle::handleInput(TetrisScreen * target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		target->moveTetromino({ -1,0 });
		target->setInputState(*new LeftPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		target->moveTetromino({ 1,0 });
		target->setInputState(*new RightPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		target->setInputState(*new DownPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		target->rotateTetromino(RotationDirection::CounterClockwise);
		target->setInputState(*new CRotationPressed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		target->rotateTetromino(RotationDirection::Clockwise);
		target->setInputState(*new RotationPressed);
	}
}

void PlayInputState::update(const float dt)
{
}

void DownPressed::handleInput(TetrisScreen * target)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		isPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isPressed) {
		target->dropTetromino();
		target->setInputState(*new Idle);
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && updateTimer >= updateDelay) {
		target->setInputState(*new Idle);
	}
}

void DownPressed::update(const float dt)
{
	updateTimer += dt;
}

void RotationPressed::handleInput(TetrisScreen * target)
{
	//target->rotateTetromino(RotationDirection::Clockwise);
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		target->setInputState(*new Idle);
	}
}

void CRotationPressed::handleInput(TetrisScreen * target)
{
	//target->rotateTetromino(RotationDirection::CounterClockwise);
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		target->setInputState(*new Idle);
	}
}
