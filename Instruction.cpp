#include "Instruction.h"

void Instruction::initiatevariables()
{
	this->leaveMenuInstruction = false;
}

//first text
void Instruction::initiatefont()
{
	if (!fontInstruction.loadFromFile("zasob/czcionki/TeleVision.ttf"))
	{
		
	}
}

void Instruction::initiatetext()
{
	this->textInstruction.setFont(this->fontInstruction);
	this->textInstruction.setFillColor(sf::Color::Color(55, 5, 5, 200));
	this->textInstruction.setCharacterSize(17);
	this->textInstruction.setLetterSpacing(1.5);
	this->textInstruction.setPosition(35, 115);
	this->textInstruction.setString(" In this game you are operating the square on the bottom of the screen, \n which is capable to move left or right. \n Your goal is to collect as many falling colored round shapes as possible, \n except for the whole red ones! \n \n Moving the squre : 'A'-left, 'D'-right \n \n Collecting colored round shapes with framing -  get 5 points \n Collecting red round shape without framing - lose 1 health \n \n At the start of the game you are given a total of 10 lives. \n The game ends when you run out of them. \n \n At any moment you are free to close the program, by pressing escape button. \n \n Press 'k' to return to the main menu.");
}

//second text
void Instruction::initiatefontHello()
{
	if (!fontHelloInInstruction.loadFromFile("zasob/czcionki/menu.otf"))
	{
		
	}
	
}

void Instruction::initiatetextHello()
{
	this->textHelloInInstruction.setFont(this->fontHelloInInstruction);
	this->textHelloInInstruction.setFillColor(sf::Color::Color(0,50,0, 255));
	this->textHelloInInstruction.setLetterSpacing(0.5);
	this->textHelloInInstruction.setString(" HELLO IN KWARTENOID ");
	this->textHelloInInstruction.setCharacterSize(45);
	this->textHelloInInstruction.setPosition(10, 35);
}


//con and des
Instruction::Instruction()
{
	this->initiatevariables();
	this->initiatefontHello();
	this->initiatetextHello();
	this->initiatefont();
	this->initiatetext();
}

Instruction::~Instruction()
{

}

bool Instruction::getLeaveMenuInstruction(bool& leaveMenuInstruction)
{
	return leaveMenuInstruction;
}

void Instruction::polleventInstruction(sf::RenderWindow* window, sf::Event& ev)
{
	//close instruction if we press 'k' button
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		this->leaveMenuInstruction = true;
	}*/
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				window->close();
			if (ev.key.code == sf::Keyboard::K)
			{
				this->leaveMenuInstruction = true;
			}
			break;
		}
	}

}

void Instruction::drawInstruction(sf::RenderWindow* window)
{
	window->draw(textInstruction);
	window->draw(textHelloInInstruction);
}

//ENGINE OF INSTRUCTION
void Instruction::runningInstruction(sf::RenderWindow* window, sf::Event& ev)
{
	while (window->isOpen() && this->getLeaveMenuInstruction(leaveMenuInstruction) == false)
	{
		this->polleventInstruction(window, ev);
		window->clear(sf::Color::Color(200, 200, 200, 255));
		this->drawInstruction(window);
		//END OF DRAWING
		window->display();
	}
	this->leaveMenuInstruction = false;
}