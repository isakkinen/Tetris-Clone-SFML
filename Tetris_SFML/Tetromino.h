#pragma once
#include <SFML/Graphics.hpp>

enum Angle
{
	North,
	East,
	South,
	West,
	Count
};

class Tetromino
{
public:
	virtual const std::vector<std::vector<bool>>& getShape() const = 0;
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle) = 0;
	virtual sf::Color getColor() const = 0;
private:
};

class OTetromino : public Tetromino
{
public:
	OTetromino();
	virtual const std::vector<std::vector<bool>>& getShape() const;
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape;
	const sf::Color color{ sf::Color::Yellow };
};

class ITetromino : public Tetromino
{
public:
	ITetromino();
	virtual const std::vector<std::vector<bool>>& getShape() const;
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape{ shape };
	const sf::Color color{ sf::Color::Cyan };
};