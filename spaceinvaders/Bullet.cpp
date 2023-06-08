#include "Bullet.h"
#include "SFML/Graphics.hpp"

Bullet::Bullet(sf::Vector2f initPos)
{
	this->initialPosition = initPos;
	this->bulletTexture.loadFromFile("bullet.png");
	this->bulletSprite.setTexture(this->bulletTexture);
	this->moveSpeed = sf::Vector2f(0.f, -5.0f);
	this->active = true;
	this->collision = false;
	this->bulletSprite.setPosition(initPos);
}

Bullet::~Bullet()
{
}

void Bullet::move()
{
	// deactive bullets not on screen
	if (this->bulletSprite.getPosition().y <= 0) {
		this->active = false;
	}
	// if still on screen then move
	this->bulletSprite.move(this->moveSpeed);
}

void Bullet::getCollided(bool status)
{
	this->collision = status;
}

bool Bullet::isActive()
{
	return this->active;
}

sf::Sprite& Bullet::getSprite()
{
	return this->bulletSprite;
}
