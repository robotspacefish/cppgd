#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create a video mode object
    sf::VideoMode vm(1920, 1080);

    // create and open a window for the game 
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);

    return 0;
}