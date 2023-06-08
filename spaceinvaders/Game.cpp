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
		if (this->entityManager->enemies.at(i)->alive == true)
			this->entityManager->enemies.at(i)->doMovement();
	}

	// if bullets are active, then move them
	for (int i = 0; i < this->entityManager->getPlayer()->bullets.size(); i++) {
		if (this->entityManager->getPlayer()->bullets.at(i)->isActive()) {
			this->entityManager->getPlayer()->bullets.at(i)->move();
		} // TODO: track which are inactive and remove them
	}
	

	// Check for collisions between bullets and enemies
	for (int i = 0; i < this->entityManager->enemies.size(); i++) {
		for (int j = 0; j < this->entityManager->getPlayer()->bullets.size(); j++) {
			// if enemy is alive and bullet active and bullet overlaps enemy 
			if ((this->entityManager->enemies.at(i)->alive == true)&& (this->entityManager->getPlayer()->bullets.at(j)->active == true) && (this->collisionHandler(this->entityManager->enemies.at(i)->getEnemyEntity().getPosition(), this->entityManager->getPlayer()->bullets.at(j)->getSprite().getPosition()))) {
				this->entityManager->enemies.at(i)->alive = false; // kill enemy
				this->entityManager->getPlayer()->bullets.at(j)->active = false; // deactivate bullet
			}
		}
	}

}

void Game::HandleDraw()
{
	this->targetWindow->getWindow().clear(sf::Color::Black); // clear screen on each frame

	this->targetWindow->getWindow().draw(this->entityManager->getPlayer()->getPlayerEntity()); // draw player

	// Draw Enemies
	for (int i = 0; i < this->entityManager->enemies.size(); i++) {
		if (this->entityManager->enemies.at(i)->alive)
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
	// rect 1 = player rect2 = bullet
bool Game::collisionHandler(sf::Vector2f rect1, sf::Vector2f rect2)
{
	std::cout << rect1.x << "and" << rect2.y << std::endl;

	if (rect1.x < rect2.x + 5 &&
		rect1.x + 25 > rect2.x &&
		rect1.y < rect2.y + 5 &&
		25 + rect1.y > rect2.y) {
		return true;
	}
	else {
		return false;
	}

	
}
