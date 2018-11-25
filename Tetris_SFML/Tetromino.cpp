#include "Tetromino.h"

OTetromino::OTetromino()
{
	// A stupid disgusting way to initialize the 2D-array
	const auto model = new bool[4][4]{ { 0, 1, 1, 0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
	for (unsigned i = 0; i < 4; ++i) {
		shape.push_back(std::vector<bool>(4));
		rotatedShape.push_back(std::vector<bool>(4));
		for (unsigned j = 0; j < 4; ++j) {
			shape[i][j] = model[i][j];
			rotatedShape[i][j] = model[i][j];
		}
	}
}

ITetromino::ITetromino()
{
	// A stupid disgusting way to initialize the 2D-array
	const auto model = new bool[4][4]{ { 0, 0, 0, 0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };
	for (unsigned i = 0; i < 4; ++i) {
		shape.push_back(std::vector<bool>(4));
		rotatedShape.push_back(std::vector<bool>(4));
		for (unsigned j = 0; j < 4; ++j) {
			shape[i][j] = model[i][j];
			rotatedShape[i][j] = model[i][j];
		}
	}
}

const std::vector<std::vector<bool>> getRotatedShape(const Angle angle, const std::vector<std::vector<bool>>& shape) {
	auto rotatedShape{ shape };
	switch (angle)
	{
	case Angle::North:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = shape[iY][iX];
			}
		}
		return rotatedShape;
		break;
	case Angle::East:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = shape[iX][3 - iY];
			}
		}
		return rotatedShape;
		break;
	case Angle::South:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = shape[3 - iY][3 - iX];
			}
		}
		return rotatedShape;
		break;
	case Angle::West:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = shape[3 - iX][iY];
			}
		}
		break;
	default:
		return shape;
	}
	return rotatedShape;
}

const std::vector<std::vector<bool>>& OTetromino::getShape(const Angle angle)
{
	rotatedShape = getRotatedShape(angle, this->shape);
	return rotatedShape;
}

sf::Color OTetromino::getColor() const
{
	return this->color;
}

const std::vector<std::vector<bool>>& ITetromino::getShape(const Angle angle)
	// Returns the shape in requested angle
{
	rotatedShape = getRotatedShape(angle, this->shape);
	return rotatedShape;
}

sf::Color ITetromino::getColor() const
{
	return this->color;
}

STetromino::STetromino()
{
	// A stupid disgusting way to initialize the 2D-array
	const auto model = new bool[4][4]{ { 0, 0, 0, 0 },{ 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 } };
	for (unsigned i = 0; i < 4; ++i) {
		shape.push_back(std::vector<bool>(4));
		rotatedShape.push_back(std::vector<bool>(4));
		for (unsigned j = 0; j < 4; ++j) {
			shape[i][j] = model[i][j];
			rotatedShape[i][j] = model[i][j];
		}
	}
}

const std::vector<std::vector<bool>>& STetromino::getShape(const Angle angle)
{
	rotatedShape = getRotatedShape(angle, this->shape);
	return rotatedShape;
}

sf::Color STetromino::getColor() const
{
	return this->color;
}

ZTetromino::ZTetromino()
{
	// A stupid disgusting way to initialize the 2D-array
	const auto model = new bool[4][4]{ { 0, 0, 0, 0 },{ 1,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 } };
	for (unsigned i = 0; i < 4; ++i) {
		shape.push_back(std::vector<bool>(4));
		rotatedShape.push_back(std::vector<bool>(4));
		for (unsigned j = 0; j < 4; ++j) {
			shape[i][j] = model[i][j];
			rotatedShape[i][j] = model[i][j];
		}
	}
}

const std::vector<std::vector<bool>>& ZTetromino::getShape(const Angle angle)
{
	rotatedShape = getRotatedShape(angle, this->shape);
	return rotatedShape;
}

sf::Color ZTetromino::getColor() const
{
	return this->color;
}

TTetromino::TTetromino()
{
	// A stupid disgusting way to initialize the 2D-array
	const auto model = new bool[4][4]{ { 0, 0, 0, 0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } };
	for (unsigned i = 0; i < 4; ++i) {
		shape.push_back(std::vector<bool>(4));
		rotatedShape.push_back(std::vector<bool>(4));
		for (unsigned j = 0; j < 4; ++j) {
			shape[i][j] = model[i][j];
			rotatedShape[i][j] = model[i][j];
		}
	}
}

const std::vector<std::vector<bool>>& TTetromino::getShape(const Angle angle)
{
	rotatedShape = getRotatedShape(angle, this->shape);
	return rotatedShape;
}

sf::Color TTetromino::getColor() const
{
	return this->color;
}

LTetromino::LTetromino()
{
	// A stupid disgusting way to initialize the 2D-array
	const auto model = new bool[4][4]{ { 0, 1, 0, 0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 } };
	for (unsigned i = 0; i < 4; ++i) {
		shape.push_back(std::vector<bool>(4));
		rotatedShape.push_back(std::vector<bool>(4));
		for (unsigned j = 0; j < 4; ++j) {
			shape[i][j] = model[i][j];
			rotatedShape[i][j] = model[i][j];
		}
	}
}

const std::vector<std::vector<bool>>& LTetromino::getShape(const Angle angle)
{
	rotatedShape = getRotatedShape(angle, this->shape);
	return rotatedShape;
}

sf::Color LTetromino::getColor() const
{
	return this->color;
}

JTetromino::JTetromino()
{
	// A stupid disgusting way to initialize the 2D-array
	const auto model = new bool[4][4]{ { 0, 1, 0, 0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 } };
	for (unsigned i = 0; i < 4; ++i) {
		shape.push_back(std::vector<bool>(4));
		rotatedShape.push_back(std::vector<bool>(4));
		for (unsigned j = 0; j < 4; ++j) {
			shape[i][j] = model[i][j];
			rotatedShape[i][j] = model[i][j];
		}
	}
}

const std::vector<std::vector<bool>>& JTetromino::getShape(const Angle angle)
{
	rotatedShape = getRotatedShape(angle, this->shape);
	return rotatedShape;
}

sf::Color JTetromino::getColor() const
{
	return this->color;
}


ITetromino Tetromino::iTetromino;
OTetromino Tetromino::oTetromino;
JTetromino Tetromino::jTetromino;
LTetromino Tetromino::lTetromino;
ZTetromino Tetromino::zTetromino;
STetromino Tetromino::sTetromino;
TTetromino Tetromino::tTetromino;
sf::Vector2i Tetromino::position{ 0,0 };
Angle Tetromino::angle{ Angle::North };


const sf::Vector2i & Tetromino::getPosition()
{
	return position;
}

void Tetromino::setPosition(const sf::Vector2i & pos)
{
	position = pos;
}

void Tetromino::move(const sf::Vector2i & dir)
{
	position += dir;
}

Angle Tetromino::getAngle()
{
	return angle;
}

void Tetromino::setAngle(const Angle a)
{
	angle = a;
}

void Tetromino::rotate(RotationDirection dir)
{
	switch (dir)
	{
	case RotationDirection::Clockwise:
		angle = static_cast<Angle>(angle + 1 > 3 ? 0 : angle + 1);
		break;
	case RotationDirection::CounterClockwise:
		angle = static_cast<Angle>(angle - 1 < 0 ? 3 : angle - 1);
		break;
	}
}
