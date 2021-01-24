#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    // the game will always be in one of four states
    enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };

    // start with the GAME_OVER state 
    State state = State::GAME_OVER;

    // get the screen resolution
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    // create an SFML window
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Zombie Arena", sf::Style::Fullscreen);

    // create a SFML View for the main action
    sf::View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    // clock for timing everything
    sf::Clock clock;

    // how long has the PLAYING state been active
    sf::Time gameTimeTotal;

    // where is the mouse in relation to the world coordinates
    sf::Vector2f mouseWorldPosition;

    // where is the mouse in relation to the screen coordinates
    sf::Vector2f mouseScreenPosition;

    // create an instance of the Player class
    Player player;

    // the boundaries of the arena
    sf::IntRect arena;

    // main game loop
    while (window.isOpen())
    {
        /*
        *************
         Handle Input
        *************
        */

        // Handle events by polling
        sf::Event event;
        while (window.pollEvent(event))
        {
            // pause game while playing 
            if (event.key.code == sf::Keyboard::Return && state == State::PLAYING)
            {
                state = State::PAUSED;
            }
            // restart while paused
            else if (event.key.code == sf::Keyboard::Return && state == State::PAUSED)
            {
                state = State::PLAYING;

                // reset the clock so there isn't a frame jump
                clock.restart();
            }
            // start a new game while in GAME_OVER state
            else if (event.key.code == sf::Keyboard::Return && state == State::GAME_OVER)
            {
                state = State::LEVELING_UP;
            }

            if (state == State::PLAYING)
            {
                // TODO
            }
        } // end event polling

         // handle player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        // handle WASD while playing
        if (state == State::PLAYING)
        {
            // handle the pressing and releasing of the WASD keys
            sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? player.moveUp() : player.stopUp();
            sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? player.moveDown() : player.stopDown();
            sf::Keyboard::isKeyPressed(sf::Keyboard::A) ? player.moveLeft() : player.stopLeft();
            sf::Keyboard::isKeyPressed(sf::Keyboard::D) ? player.moveRight() : player.stopRight();
        }
    }
    return 0;
}