#pragma once
#include "MyWindow.h"
#include "EntityManager.h"
#include "SFML/Graphics.hpp"

class Game
{

	// Takes a window and runs a game in that window

public:
	Game(MyWindow*, EntityManager*);
	~Game();
		

	void HandleInput();
	void HandleUpdate();
	void HandleDraw();

	bool collisionHandler(sf::Vector2f, sf::Vector2f);

	void StartGame();

private:
	MyWindow* targetWindow;
	EntityManager* entityManager;
};

