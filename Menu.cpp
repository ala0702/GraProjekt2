#include "Menu.h"


//private functions

void Menu::initiatevariables()
{
	
	// 0 - play
	// 1 - instruction
	// 2 - exit 
}

void Menu::initiatefont()
{
	if (!fontMenu.loadFromFile("zasob/czcionki/menu.otf"))
	{
		
	}
}

void Menu::initiatetext()
{
	this->menu[0].setFont(this->fontMenu);
	this->menu[0].setFillColor(Color::Red);
	this->menu[0].setString("Play");
	this->menu[0].setCharacterSize(50);
	this->menu[0].setPosition(290, 80);

	this->menu[1].setFont(this->fontMenu);
	this->menu[1].setFillColor(Color::Color(255, 5, 5, 150));
	this->menu[1].setString("Instructions");
	this->menu[1].setCharacterSize(50);
	this->menu[1].setPosition(120, 270);

	this->menu[2].setFont(this->fontMenu);
	this->menu[2].setFillColor(Color::Color(255, 5, 5, 150));
	this->menu[2].setString("Exit");
	this->menu[2].setCharacterSize(50);
	this->menu[2].setPosition(290, 460);
}

// constructor and destructor
Menu::Menu()
{
	this->initiatevariables();
	this->initiatefont();
	this->initiatetext();
}

Menu::~Menu()
{

}

// public functions 

void Menu::ColorMove()
{
	for(int i=0; i<3; i++)
	{
		if (i == this->selectedItem)
		{
			this->menu[i].setFillColor(Color::Red);
		}

		else 
		{
			this->menu[i].setFillColor(Color::White);
		}
	}
	sf::sleep(sf::milliseconds(100));
}

int Menu::getSelectedItem(int& selectedItem)
{
	return selectedItem;
}

// * checks if we pushed 'w' or 's' 
// * set color of buttoms

void Menu::polleventsMenu()
{
	//down:
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//*set new select item 
		//*setting right colors
		if (this->selectedItem == 0)
			this->selectedItem = 1;

		else if (this->selectedItem == 1)
			this->selectedItem = 2;

		else if (this->selectedItem == 2)
			this->selectedItem = 0;
		
		for (int i = 0; i < 3; i++)
		{
			if (i == this->selectedItem)
			{
				{
					this->menu[i].setFillColor(Color::Red);
				}
			}
			else
			{
				this->menu[i].setFillColor(Color::White);
			}
		}
		sf::sleep(sf::milliseconds(100));
	}

	//UP
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//*set new select item 
		//*setting right colors
		if (this->selectedItem == 0)
			this->selectedItem = 2;
		else if (this->selectedItem == 1)
			this->selectedItem = 0;
		else if (this->selectedItem == 2)
			this->selectedItem = 1;

		for (int i = 0; i < 3; i++)
		{
			if (i == this->selectedItem)
			{
				{
					this->menu[i].setFillColor(Color::Red);
				}
			}
			else
			{
				this->menu[i].setFillColor(Color::White);
			}
		}
		sf::sleep(sf::milliseconds(100));
	}
}

void Menu::updateMenu(sf::RenderWindow* window)
{
	this->ColorMove();
	this->polleventsMenu();
}

void Menu::drawMenu(sf::RenderWindow* window)
{
	for (int i = 2; i >= 0; i--)
	{
		window->draw(menu[i]);
	}
}