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

	return 0;
}