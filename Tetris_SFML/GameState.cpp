#include "GameState.h"

Play::Play(const sf::Vector2f& position, 
	const sf::Vector2u& areaSize,
	const sf::Vector2f& blockSize)
	:tetris(position,blockSize)
{
}

void Play::update(const float dt)
{
	tetris.update(dt);
}

void Play::handleInput()
{
	tetris.handleInput();
}

void Play::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(tetris);
}
