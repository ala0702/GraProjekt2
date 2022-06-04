#include "player.h"

void player::initVariables()
{

}

void player::initiateRshape()
{
	this->Rshape.setFillColor(sf::Color::Color(200,50,200,170));
	this->Rshape.setSize(sf::Vector2f(50.f, 50.f));
}

player::player()
{
	this->initiateRshape();
}

player::~player()
{
}

void player::update(sf::RenderTarget* target)
{
}

void player::render(sf::RenderTarget* target)
{
	target->draw(this->Rshape);
}
