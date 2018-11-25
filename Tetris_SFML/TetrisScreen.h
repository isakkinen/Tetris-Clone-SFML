#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Block.h"
#include "Tetromino.h"
#include "InputState.h"

class TetrisScreen : public sf::Drawable, public sf::Transformable
	// Handles the tetrominos and the whole play area
{
public:

public:
	// Public methods
	TetrisScreen(const sf::Vector2f& position, const sf::Vector2f& blockSize = { 32.0f,32.0f });
	void update(const float dt);
	void handleInput();
	void setInputState(PlayInputState& state);
	void moveTetromino(const sf::Vector2i& dir);
	void dropTetromino();
	void rotateTetromino(const RotationDirection direction);
private: 
	// Private methods
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void clearScreen();
	void scanLines();
	void destroyLine(const unsigned y);
	void advanceTimer(const float dt);
	void resetTimer();
	void skipStep();
	void drawTetromino();
	void newTetromino();
	void plantTetromino();
	bool canMove(const sf::Vector2i& dir);
private:
	// Private members
	static constexpr unsigned width{ 10 };
	static constexpr unsigned height{ 20 };
	static constexpr unsigned borderWidth{ 4 };
	static constexpr unsigned borderHeight{ 4 };
	static constexpr float updateDelay{ 30.0f };
	const sf::Vector2i spawnPosition{ 4,-2 };
	const sf::Color boardColor{ sf::Color::Black };
	const sf::Color backgroundColor{ sf::Color::White };
	float updateTimer{ 0.0f };
	sf::RectangleShape background;
	Block gameBoard[height][width];
	Tetromino* currentTetromino;
	sf::Vector2i tetrominoPosition{ spawnPosition };
	PlayInputState* inputState{ new Idle };
	Angle tetrominoAngle{ Angle::North };

	std::random_device rd;
	std::mt19937 rng{ rd() };
	std::uniform_int_distribution<int> uni{ 0, 6 };
};