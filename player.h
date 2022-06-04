#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class player
{
private:
	sf::RectangleShape Rshape;

	//private functions

	void initVariables(); 
	void initiateRshape();


public:
	//constructor and destructor
	player();
	~player();

	//main update and render 
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};

