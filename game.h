#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class game
{
private:
	//window and event
	sf::VideoMode vm; //holds the information about height and wight of the window
	sf::RenderWindow* window; //
	sf::Event event; //

	//private functions (initialize things)
	void initiateWindow();


public:
	//constructor and destructor
	game();
	~game();

	//accessors

	//update
	void pollEvent(); //checks events

	//main update and render
	void update();
	void render();

	//main runnning game, engine;))
	void running();

};

