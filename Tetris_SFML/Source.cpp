#include <SFML/Graphics.hpp>
#include <chrono>
#include "Game.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 900), "Tetris");

	auto tp{ std::chrono::system_clock::now() };
	static constexpr float FRAME_RATE{ 60.0f };
	static GameState* state = new Play({ 200.0f,100.0f });

	Game game(state);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt;
		{
			auto new_tp{ std::chrono::system_clock::now() };
			dt = std::chrono::duration<float>(new_tp - tp).count();
			tp = new_tp;
		}

		game.handleInput();
		game.update(dt*FRAME_RATE);

		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}