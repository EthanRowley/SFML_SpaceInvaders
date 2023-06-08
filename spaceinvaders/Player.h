#pragma once
#include "SFML/Graphics.hpp"
#include "Bullet.h"

class Player
{

public:
	Player();
	~Player();

	void move();
	void shoot();

	sf::Sprite& getPlayerEntity();
	sf::Vector2f playerPosition;
	sf::Texture playerTexture;


	int shootTimer;
	int SHOOT_DELAY;
	sf::Vector2f MOVE_SPEED;
	std::vector<Bullet*> bullets;

private:
	sf::Sprite playerEntity;

};

