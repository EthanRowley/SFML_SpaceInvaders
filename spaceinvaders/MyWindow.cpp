#include "MyWindow.h"


// Create game window
MyWindow::MyWindow(int width, int height)
{
	this->window.create(sf::VideoMode(width, height), "Space Invaders", sf::Style::Default); 
	this->setWindowWidthHeight(width, height); // set width and heigh variables
	this->window.setFramerateLimit(60);
}

// Cant be used to close window or it causes an error?
MyWindow::~MyWindow()
{ 
	
}



























//////////////////////////// GETTERS AND SETTERS ////////////////////////////
void MyWindow::setWindowWidthHeight(int w, int h)
{
	this->windowWidth = w;
	this->windowHeight = h;
}

int MyWindow::getWindowHeight()
{
	return this->windowHeight;
}

int MyWindow::getWindowWidth()
{
	return this->windowWidth;
}
sf::RenderWindow& MyWindow::getWindow()
{
	return this->window;
}
///////////////////////////////////////////////////////////////////////////