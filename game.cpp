#include "game.h"


//private functions
void game::initiateWindow()
{
	this->vm = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->vm, "PROJECT GAME", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

//constructor
game::game()
{
	this->initiateWindow();
}

//destructor
game::~game()
{
	delete this->window;
}


//public functions
void game::pollEvent()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}




	//main functions 
// *update
// *render
// *running the game
void game::update()
{
	this->pollEvent();
}

void game::render()
{
	this->window->clear();

	//DRAWING OBJECTS

	//END OF DRAWING

	this->window->display();
}

void game::running()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
