#pragma once
#include <SFML/Graphics/RenderWindow.hpp>


class MyWindow
{
	// Window class to create window and detect events
public:
	MyWindow(int, int);
	~MyWindow();

	void setWindowWidthHeight(int, int);
	int getWindowHeight();
	int getWindowWidth();

	sf::RenderWindow& getWindow();

private:
	sf::RenderWindow window;

	int windowWidth;
	int windowHeight;
};

