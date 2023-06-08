#pragma once
#include "SFML/Graphics.hpp"

class Enemy
{
public:
	Enemy(float, float);
	~Enemy();

	sf::Sprite& getEnemyEntity();

	sf::Texture enemyTexure;
	sf::Vector2f moveSpeed;

	bool movingLeft;
	void doMovement();

protected:
	sf::Sprite enemyEntity;
};

