#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create a video mode object
    sf::VideoMode vm(1920, 1080);

    // create and open a window for the game 
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);

    while (window.isOpen())
    {
        /** Handle Player Input */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
    }

    return 0;
}