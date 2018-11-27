#include "Game.h"

Game::Game(GameState * initState)
	:state(initState)
{
}

void Game::update(const float dt)
{
	state->update(dt);
}

void Game::handleInput()
{
	state->handleInput(this);
}

void Game::setState(GameState * target)
{
	state = target;
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(*state);
}
