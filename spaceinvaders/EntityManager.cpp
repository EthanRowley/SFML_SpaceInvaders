#include "EntityManager.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Enemy.h"
#include <vector>

EntityManager::EntityManager()
{
	// Initialise player
	Player* p = new Player();
	this->player = p;

	// Create Enemies and add to enemies vector
	for (int i = 1; i < 14; i++) {
		for (int j = 1; j < 5; j++) {
			Enemy* e = new Enemy(i * 35.0f, j*25.0f);
			this->enemies.push_back(e);
		}
	}

}

EntityManager::~EntityManager()
{
	delete player;
}

// Returns pointer to player class
Player* EntityManager::getPlayer()
{
	return this->player;
}



