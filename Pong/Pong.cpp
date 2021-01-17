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

	return 0;
}