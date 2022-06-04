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
	int selectedItem;


	Font font;
	Text menu[3];

public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
};

