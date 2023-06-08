#include "Player.h"
#include "SFML/Graphics.hpp"
#include "EntityManager.h"
#include "Bullet.h"
#include <iostream>

Player::Player()
{
	this->playerTexture.loadFromFile("player.png");

	sf::Sprite s;
	s.setTexture(this->playerTexture);
	s.setPosition(250 - (25 / 2), 700);

	this->playerPosition = sf::Vector2f((250 - (25 / 2)), 700);
	this->playerEntity = s;
	this->shootTimer = 0; // Prevents space bar being pressed every frame

	// Constants, Idk if they should be here but they are, not const incase they need to be changed later
	this->SHOOT_DELAY = 20;
	this->MOVE_SPEED = sf::Vector2f(2.5f, 0.0f);
}

Player::~Player()
{

}

void Player::move()
{
	// Detect inputs an manipulate copy of players location for movement
	// Collision detection included
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->playerPosition.x > 0) {
		this->playerPosition -= this->MOVE_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->playerPosition.x + 25 <= 500) {
		this->playerPosition += this->MOVE_SPEED;
	}

	// Handles detecting spacebar press for shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		shootTimer++;
		if (shootTimer >= this->SHOOT_DELAY) {
			this->shoot();
			shootTimer = 0;
		}
	}

}

void Player::shoot()
{
	std::cout << "shot fired at: "<< this->playerPosition.x << std::endl;
	Bullet* b = new Bullet(this->playerPosition);
	this->bullets.push_back(b);
}

// returns reference of players SFML entity
sf::Sprite& Player::getPlayerEntity()
{
	return this->playerEntity;
}
