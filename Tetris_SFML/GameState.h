#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "TetrisScreen.h"
class GameState : public sf::Drawable, public sf::Transformable
	// An interface for different states of the game f.e. Play, Menu, etc.
{
public:
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

class Play : public GameState
	// Play the game!
{
public:
	Play(const sf::Vector2f& position, 
		const sf::Vector2u& areaSize = { 10,20 }, 
		const sf::Vector2f& blockSize = { 32.0f,32.0f });
	void update(const float dt);
	void handleInput();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	TetrisScreen tetris;
};