#include "Bat.h"
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

	// TODO add ball

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

	while (window.isOpen()
	{

		// TODO
		/* Handle player input */

		/* update bat, ball, and HUD */

		/* draw bat, ball, and HUD */
	}
	return 0;
}