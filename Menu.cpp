#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("timesi.ttf"))
	{

	}

	selectedItem = 1;

	menu[0].setColor(Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(width / 2, height / 4);

	menu[1].setColor(Color::Yellow);
	menu[1].setString("Instructions");
	menu[1].setPosition(width / 2, height / 8);
	
	menu[2].setColor(Color::Yellow);
	menu[2].setString("Exit");
	menu[2].setPosition(width / 2, height / 12);
}

Menu::~Menu()
{

}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);
	}
}