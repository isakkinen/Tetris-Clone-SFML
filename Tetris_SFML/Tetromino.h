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

class ITetromino;
class OTetromino;
class JTetromino;
class LTetromino;
class ZTetromino;
class STetromino;
class TTetromino;

class Tetromino
{
public:
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle) = 0;
	virtual sf::Color getColor() const = 0;
	static ITetromino iTetromino;
	static OTetromino oTetromino;
	static JTetromino jTetromino;
	static LTetromino lTetromino;
	static ZTetromino zTetromino;
	static STetromino sTetromino;
	static TTetromino tTetromino;
private:
};


class OTetromino : public Tetromino
{
public:
	OTetromino();
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
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape{ shape };
	const sf::Color color{ sf::Color::Cyan };
};

class STetromino : public Tetromino
{
public:
	STetromino();
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape{ shape };
	const sf::Color color{ sf::Color::Cyan };
};

class ZTetromino : public Tetromino
{
public:
	ZTetromino();
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape{ shape };
	const sf::Color color{ sf::Color::Cyan };
};

class TTetromino : public Tetromino
{
public:
	TTetromino();
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape{ shape };
	const sf::Color color{ sf::Color::Cyan };
};

class LTetromino : public Tetromino
{
public:
	LTetromino();
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape{ shape };
	const sf::Color color{ sf::Color::Cyan };
};

class JTetromino : public Tetromino
{
public:
	JTetromino();
	virtual const std::vector<std::vector<bool>>& getShape(const Angle angle);
	virtual sf::Color getColor() const;
private:
	std::vector<std::vector<bool>> shape;
	std::vector<std::vector<bool>> rotatedShape{ shape };
	const sf::Color color{ sf::Color::Cyan };
};

