#include "Game.h"
#include "MyWindow.h"
#include "SFML/Graphics.hpp"
#include "EntityManager.h"
#include <iostream>

Game::Game(MyWindow* w, EntityManager* e)
{
	this->targetWindow = w;
	this->entityManager = e;
}



void Game::StartGame()
{

	while (this->targetWindow->getWindow().isOpen()) {
		sf::Event event;
		while (this->targetWindow->getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->targetWindow->getWindow().close(); // Close game window
			}
		}

		// Main Game Logic
		this->HandleInput();
		this->HandleUpdate();
		this->HandleDraw();

	}
}


void Game::HandleInput()
{
	this->entityManager->getPlayer()->move(); // Player movement function
}

void Game::HandleUpdate()
{
	// Change location of player
	this->entityManager->getPlayer()->getPlayerEntity().setPosition(this->entityManager->getPlayer()->playerPosition);

	// tell enemies to move
	for (int i = 0; i < this->entityManager->enemies.size(); i++) {
		this->entityManager->enemies.at(i)->doMovement();
	}

	// if bullets are active, then move them
	for (int i = 0; i < this->entityManager->getPlayer()->bullets.size(); i++) {
		if (this->entityManager->getPlayer()->bullets.at(i)->isActive()) {
			this->entityManager->getPlayer()->bullets.at(i)->move();
		} // TODO: track which are inactive and remove them
	}

}

void Game::HandleDraw()
{
	this->targetWindow->getWindow().clear(sf::Color::Black); // clear screen on each frame

	this->targetWindow->getWindow().draw(this->entityManager->getPlayer()->getPlayerEntity()); // draw player

	// Draw Enemies
	for (int i = 0; i < this->entityManager->enemies.size(); i++) {
		this->targetWindow->getWindow().draw(this->entityManager->enemies.at(i)->getEnemyEntity());
	}

	// Draw active bullets
	for (int i = 0; i < this->entityManager->getPlayer()->bullets.size(); i++) {
		if (this->entityManager->getPlayer()->bullets.at(i)->isActive()) {
			this->targetWindow->getWindow().draw(this->entityManager->getPlayer()->bullets.at(i)->getSprite());
		} 
	}


	this->targetWindow->getWindow().display(); // update display
}