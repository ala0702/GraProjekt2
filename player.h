#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class player
{
private:
	//sf::RectangleShape Rshape;

	//variables
	float movementSpeed; //how fast the player moves / how much the player will move

	//private functions

	void initVariables(); 
	void initiateRshape();
	


public:

	sf::RectangleShape Rshape;

	//constructor and destructor
	player();
	~player();



	void updateInput();  // we move the player
	void updateCollision(sf::RenderTarget* target);

	//main update and render 
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);



};

