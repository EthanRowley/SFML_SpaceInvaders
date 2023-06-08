#include "main.h"
#include "SFML/Graphics.hpp"
#include "MyWindow.h"
#include "EntityManager.h"
#include "Game.h"



int main() {

	MyWindow* window = new MyWindow(500, 800); // Create a window
	EntityManager* entityManager = new EntityManager();
	Game* game = new Game(window, entityManager);

	game->StartGame(); 

	return 0;
}
