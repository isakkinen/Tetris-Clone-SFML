#include "Block.h"

Block::Block(const sf::Vector2f position, const sf::Vector2f size, const sf::Color & color)
{
	block = sf::RectangleShape();
	block.setPosition(position);
	block.setSize(size);
	block.setFillColor(color);
	this->color = color;
}

void Block::update(const float dt)
{
	block.setFillColor(color);
}

void Block::setColor(const sf::Color & color)
{
	this->color = color;
}

sf::Color Block::getColor() const
{
	return this->color;
}

bool Block::isPlanted() const
{
	return planted;
}

void Block::plant()
{
	planted = true;
}

void Block::unplant()
{
	planted = false;
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(block);
}
