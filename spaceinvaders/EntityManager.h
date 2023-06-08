#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>

class EntityManager
{

public:
	EntityManager();
	~EntityManager();


	Player* getPlayer(); 
	std::vector<Enemy*> enemies;


private:
	Player* player;

};

