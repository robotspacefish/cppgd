#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	// create a video mode object 
	sf::VideoMode vm(1920, 1080);

	// create and open a window for the game 
	sf::RenderWindow window(vm, "Pong", sf::Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// create a bat at the bottom center of the screen
	Bat bat(1920 / 2, 1080 - 20);

	// create ball 
	Ball ball(1920 / 2, 0);

	// create HUD
	sf::Text hud;

	// retro style font 
	sf::Font font;
	font.loadFromFile("fonts/DS-DIGI.ttf");

	hud.setFont(font);

	hud.setCharacterSize(75);

	hud.setFillColor(sf::Color::White);

	hud.setPosition(20, 20);

	// clock for timing everyting
	sf::Clock clock;

	while (window.isOpen())
	{
		/* Handle player input */

		sf::Event event;

		while (window.pollEvent(event))
		{
			// quit the game when the window is closed
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// handle player quitting 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		// handle pressing and releasing of the arrow keys 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		/* update bat, ball, and HUD */

		// update the delta time 
		sf::Time dt = clock.restart();

		bat.update(dt);
		ball.update(dt);

		// update HUD text 
		std::stringstream ss;
		ss << "Score:" << score << " Lives:" << lives;
		hud.setString(ss.str());

		/* draw bat, ball, and HUD */
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}
	return 0;
}