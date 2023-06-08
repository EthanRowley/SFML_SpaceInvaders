#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{

public:
	Bullet(sf::Vector2f);
	~Bullet();
	
	sf::Texture bulletTexture;
	sf::Vector2f moveSpeed;

	void move();
	bool detectCollision();

	bool isActive();
	sf::Sprite& getSprite();

	bool active;
	int lifeSpan = 5;

protected:
	sf::Vector2f initialPosition;
	sf::Sprite bulletSprite;
};

