#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	// where is the player
	sf::Vector2f m_Position;

	sf::Sprite m_Sprite;

	sf::Texture m_Texture;

	// what is the screen resolution
	sf::Vector2f m_Resolution;

	// what size is the current arena 
	sf::IntRect m_Arena;

	// how big is each tile of the arena
	int m_TileSize;

	// which direction(s) is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	int m_Health;
	int m_MaxHealth;

	// when was the player last hit
	sf::Time m_LastHit;

	// speed in pixels per second
	float m_Speed;

public:
	// constructor
	Player();

	void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);

	// call this at the end of every game 
	void resetPlayerStats();

	// handle the player getting hit by a zombie
	bool hit(sf::Time timeHit);

	// how long ago was the player last hit
	sf::Time getLastHitTime();

	// where is the player
	sf::FloatRect getPosition();

	// where is the center of the player
	sf::Vector2f getCenter();

	// what angle is the player facing
	float getRotation();

	// send a copy of the sprite to the main function 
	sf::Sprite getSprite();

	// move player
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	// stop movement in specific direction
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	// call once every frame
	void update(float elapsedTime, sf::Vector2i mousePosition);

	// give player a speed boost
	void upgradeSpeed();

	// give player some health
	void upgradeHealth();

	// increase max amount of health the player can have
	void increaseHealthLevel(int amount);

	// how much health has the player currently got?
	int getHealth();
};