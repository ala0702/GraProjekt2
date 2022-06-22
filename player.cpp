#include "Player.h"

//private functions
//variables
void Player::initVariables()
{
	this->movementSpeed = 5.f;

}
//Rshape
void Player::initiateRshape()
{
	this->Rshape.setFillColor(sf::Color::Color(200,50,200,170));
	this->Rshape.setSize(sf::Vector2f(50.f, 50.f));
	this->Rshape.setPosition(0.f, 550.f);
}


//constructor
Player::Player()
{
	this->initiateRshape();
	this->initVariables();
}
//descructor
Player::~Player()
{
}


//public functions

// * moving the player (left and right)
void Player::updateInput()
{
	//key pressed
	
	//left:
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->Rshape.move(-this->movementSpeed, 0.f);
	}

	//right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->Rshape.move(this->movementSpeed, 0.f);
	}

}

void Player::updateCollision(sf::RenderTarget* target)
{
	//left
	if (this->Rshape.getGlobalBounds().left <= 0.f) //left - x lrfto corner, top- y  
	{
		this->Rshape.setPosition(0.f, this->Rshape.getGlobalBounds().top);
	}

	//right
	if (this->Rshape.getGlobalBounds().left + this->Rshape.getSize().x >= target->getSize().x)
	{
		this->Rshape.setPosition(target->getSize().x - Rshape.getSize().x, this->Rshape.getGlobalBounds().top);
	}
}



//MAIN update and render
void Player::update(sf::RenderTarget* target)
{
	this->updateInput();
	this->updateCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->Rshape);
}
