#pragma once
#include "MyWindow.h"
#include "EntityManager.h"

class Game
{

	// Takes a window and runs a game in that window

public:
	Game(MyWindow*, EntityManager*);
	~Game();
		

	void HandleInput();
	void HandleUpdate();
	void HandleDraw();

	void StartGame();

private:
	MyWindow* targetWindow;
	EntityManager* entityManager;
};

