#include "Enemy.h"
#include "SFML/Graphics.hpp"

Enemy::Enemy(float x, float y)
{
	this->enemyTexure.loadFromFile("enemy.png");
	this->enemyEntity.setTexture(this->enemyTexure);
	this->enemyEntity.setPosition(sf::Vector2f(x,y));

	this->moveSpeed = sf::Vector2f(1.0f, 0.f);
	this->movingLeft = false;
}

sf::Sprite& Enemy::getEnemyEntity()
{
	return this->enemyEntity;
}

// Method to move enemy to the side and then down a level
void Enemy::doMovement()
{
	if (this->enemyEntity.getPosition().x + this->moveSpeed.x + 25.f >= 500) {
		movingLeft = true;
		this->enemyEntity.move(sf::Vector2f(0.f, 100.f));
	} else if (this->enemyEntity.getPosition().x - this->moveSpeed.x <= 0) {
		movingLeft = false;
		this->enemyEntity.move(sf::Vector2f(0.f, 100.f));
	}

	// -> Moving to the left
	if (movingLeft) {
		// -> Moving down a level
		this->enemyEntity.move(-(this->moveSpeed));
	}

	// -> Moving to the right
	if (!movingLeft) {
		this->enemyEntity.move(this->moveSpeed);
	}
}
