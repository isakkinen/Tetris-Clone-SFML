#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "TetrisScreen.h"
//#include "Game.h"

class Game;
class Play;
class MainMenu;

class GameState : public sf::Drawable, public sf::Transformable
	// An interface for different states of the game f.e. Play, Menu, etc.
{
public:
	virtual void update(const float dt) = 0;
	virtual void handleInput(Game* target) = 0;
	static Play play;
	static MainMenu menu;

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
	void handleInput(Game* target);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	TetrisScreen tetris;
};

class MainMenu : public GameState
{
public:
	MainMenu(const sf::Vector2f& position);
	void update(const float dt);
	void handleInput(Game* target);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Text title;
	sf::Text prompt;
	sf::Font font;
};