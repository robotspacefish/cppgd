#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    // the game will always be in one of four states
    enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };

    // start with the GAME_OVER state 
    State state = State::GAME_OVER;

    // get the screen resolution and create an SFML window
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

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

    }
    return 0;
}