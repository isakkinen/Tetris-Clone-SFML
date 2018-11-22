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

const std::vector<std::vector<bool>>& OTetromino::getShape() const
{
	return this->shape;
}

const std::vector<std::vector<bool>>& OTetromino::getShape(const Angle angle)
{
	switch (angle)
	{
	case Angle::North:
		return rotatedShape;
		break;
	case Angle::East:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = this->shape[3 - iX][3 - iY];
			}
		}
		return rotatedShape;
		break;
	case Angle::South:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = this->shape[3 - iY][iX];
			}
		}
		return rotatedShape;
		break;
	case Angle::West:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = this->shape[3 - iX][3 - iY];
			}
		}
		break;
	default:
		return this->shape;
	}
	return rotatedShape;
}

sf::Color OTetromino::getColor() const
{
	return this->color;
}

const std::vector<std::vector<bool>>& ITetromino::getShape() const
{
	return this->shape;
}

const std::vector<std::vector<bool>>& ITetromino::getShape(const Angle angle)
	// Returns the shape in requested angle
{
	switch (angle)
	{
	case Angle::North:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = this->shape[iY][iX];
			}
		}
		return rotatedShape;
		break;
	case Angle::East:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = this->shape[iX][3-iY];
			}
		}
		return rotatedShape;
		break;
	case Angle::South:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = this->shape[3-iY][3-iX];
			}
		}
		return rotatedShape;
		break;
	case Angle::West:
		for (unsigned iY = 0; iY < 4; ++iY) {
			for (unsigned iX = 0; iX < 4; ++iX) {
				rotatedShape[iY][iX] = this->shape[3-iX][iY];
			}
		}
		break;
	default:
		return this->shape;
	}
	return rotatedShape;
}

sf::Color ITetromino::getColor() const
{
	return this->color;
}

