#pragma once
#include "GameState.h"
class Game : public sf::Drawable, public sf::Transformable
{
public:
	Game(GameState* initState);
	void update(const float dt);
	void handleInput();
	void setState(GameState* target);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	GameState * state;

};