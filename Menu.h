#pragma once
#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Menu
{
private:
	//const int itemsNumber = 3;

	friend class Game;

	Font fontMenu;
	int selectedItem = 0;
	
	//private functions 
	// *initiate things
	void initiatevariables();
	void initiatefont();
	void initiatetext();

public:
	
	Text menu[3];
	//destructor and constructor i guess
	Menu();
	~Menu();


	//public functions
	//moving options
	// *changes the color
	void ColorMove();
	
	int getSelectedItem(int &selectedItem);

	//poll events
	void polleventsMenu();

	//update
	void updateMenu(sf::RenderWindow* window);


	//render 
	void drawMenu(sf::RenderWindow* window);

};