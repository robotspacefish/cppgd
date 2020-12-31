#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create a video mode object
    sf::VideoMode vm(1920, 1080);

    // create and open a window for the game 
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);

    // create a texture to hold a graphic on the GPU
    sf::Texture textureBackground;

    // load a graphic into the texture 
    textureBackground.loadFromFile("graphics/background.png");

    // create a sprite 
    sf::Sprite spriteBackground;

    // attach the texture to the sprite 
    spriteBackground.setTexture(textureBackground);

    // set the spriteBackground to cover the screen
    spriteBackground.setPosition(0, 0);

    // make a tree sprite
   sf::Texture textureTree;
   textureTree.loadFromFile("graphics/tree.png");
   sf::Sprite spriteTree;
   spriteTree.setTexture(textureTree);
   spriteTree.setPosition(810, 0);

    while (window.isOpen())
    {
        /** Handle Player Input */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        /** Update Scene */
        // TODO

        /** Draw Scene */
        window.clear();

        // Draw
        window.draw(spriteBackground);

        window.draw(spriteTree);

        // Show everything we just drew
        window.display();

    }

    return 0;
}