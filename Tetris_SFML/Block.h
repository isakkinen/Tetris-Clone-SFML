#pragma once
#include <SFML/Graphics.hpp>
class Block : public sf::Drawable, public sf::Transformable
{
public:
	Block(const sf::Vector2f position = { 0.0f,0.0f },
		const sf::Vector2f size = { 0.0f,0.0f },
		const sf::Color& color = sf::Color::Red);
	void update(const float dt);
	void setColor(const sf::Color& color);
	sf::Color getColor() const;
	bool isPlanted() const;
	void plant();
	void unplant();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape block;
	sf::Color color;
	bool planted{ false };
};