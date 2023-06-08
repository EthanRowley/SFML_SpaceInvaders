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
	void getCollided(bool);

	bool isActive();
	sf::Sprite& getSprite();

	bool active;
	bool collision;
	int lifeSpan = 5;

protected:
	sf::Vector2f initialPosition;
	sf::Sprite bulletSprite;
};

