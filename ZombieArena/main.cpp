#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ZombieArena.h"

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
    sf::Vector2i mouseScreenPosition;

    // create an instance of the Player class
    Player player;

    // the boundaries of the arena
    sf::IntRect arena;

    // create the background
    sf::VertexArray background;
    // load the texture 
    sf::Texture textureBackground;
    textureBackground.loadFromFile("graphics/background_sheet.png");

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
        } // end WASD while playing

        // handle LEVELING up state
        if (state == State::LEVELING_UP)
        {
            // handle player LEVELING up
            if (event.key.code == sf::Keyboard::Num1)
            {
                state = State::PLAYING;
            }

            if (event.key.code == sf::Keyboard::Num2)
            {
                state = State::PLAYING;
            }
            
            if (event.key.code == sf::Keyboard::Num3)
            {
                state = State::PLAYING;
            }

            if (event.key.code == sf::Keyboard::Num4)
            {
                state = State::PLAYING;
            }
            
            if (event.key.code == sf::Keyboard::Num5)
            {
                state = State::PLAYING;
            }

            if (event.key.code == sf::Keyboard::Num6)
            {
                state = State::PLAYING;
            }

            if (state == State::PLAYING)
            {
                // prepare the level
                arena.width = 500;
                arena.height = 500;
                arena.left = 0;
                arena.top = 0;

                // pass the vertex array by reference
                int tileSize = createBackground(background, arena);

                // spawn player in the middle of the arena 
                player.spawn(arena, resolution, tileSize);

                // reset the clock so there isn't a frame jump
                clock.restart();
            } // end LEVELING up
        }

        /*
        * ************
        * UPDATE FRAME
        * ************
        */
        if (state == State::PLAYING)
        {
            // update the delta time
            sf::Time dt = clock.restart();

            // update the total game time
            gameTimeTotal += dt;

            // make a decimal fraction of 1 from the delta time 
            float dtAsSeconds = dt.asSeconds();

            // where is the mouse pointer
            mouseScreenPosition = sf::Mouse::getPosition();

            // convert mouse position to world coordinates of mainView
            mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(), mainView);

            // update the player
            player.update(dtAsSeconds, sf::Mouse::getPosition());

            // make note of player's new position
            sf::Vector2f playerPosition(player.getCenter());

            // make the view center around the player
            mainView.setCenter(player.getCenter());
        } // end updating the scene

        /*
        * **************
        * DRAW THE SCENE
        * **************
        */
        if (state == State::PLAYING)
        {
            window.clear();

            // set the mainView to be displayed in the window
            // and draw everything related to it
            window.setView(mainView);

            // draw background
            window.draw(background, &textureBackground);

            // draw player
            window.draw(player.getSprite());
        }

        if (state == State::LEVELING_UP)
        {
            // TODO
        }

        if (state == State::PAUSED)
        {
            // TODO
        
        }
        if (state == State::GAME_OVER)
        {
            // TODO
        }

        window.display();

    } // end game loop
    return 0;
}