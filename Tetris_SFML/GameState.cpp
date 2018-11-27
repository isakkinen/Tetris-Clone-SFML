#include "GameState.h"
#include "Game.h"

Play::Play(const sf::Vector2f& position, 
	const sf::Vector2u& areaSize,
	const sf::Vector2f& blockSize)
	:tetris(position,blockSize)
{
}

void Play::update(const float dt)
{
	tetris.update(dt);
}

void Play::handleInput(Game* target)
{
	tetris.handleInput();
}

void Play::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(tetris);
}

Play GameState::play{ {200.0f,100.0f} };
MainMenu GameState::menu{ {400.0f,300.0f} };

MainMenu::MainMenu(const sf::Vector2f & position)
{
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Error loading font file!\n";
	}
	title.setFont(font);
	title.setCharacterSize(72);
	title.setString("TETRIS");
	title.setOrigin({ title.getGlobalBounds().width/2,title.getGlobalBounds().height/2 });
	title.setPosition(position);
	prompt.setFont(font);
	prompt.setString("Press SPACE to start!");
	prompt.setOrigin({ prompt.getGlobalBounds().width/2,prompt.getGlobalBounds().height/2 });
	prompt.setPosition(position.x, position.y + 100.0f);
}

void MainMenu::update(const float dt)
{
	// Nothing to see here!
}

void MainMenu::handleInput(Game* target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {

		std::cout << "Game start requested!\n";
		target->setState(&GameState::play);
	}
}

void MainMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(title);
	target.draw(prompt);
}
