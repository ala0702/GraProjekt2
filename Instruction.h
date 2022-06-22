#pragma once
#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class Instruction
{
private:

	bool leaveMenuInstruction;

	friend class Game;

	//
	sf::Font fontHelloInInstruction;
	sf::Text textHelloInInstruction;

	sf::Font fontInstruction;
	sf::Text textInstruction;


	//private functions 
	// *initiate things
	void initiatevariables();

	void initiatefont();
	void initiatetext();

	void initiatefontHello();
	void initiatetextHello();


public:
	//destructor and constructor i guess
	Instruction();
	~Instruction();


	//public functions

	//accesors
	bool getLeaveMenuInstruction(bool& leaveMenu);

	//poll events
	void polleventInstruction(sf::RenderWindow* window, sf::Event& ev);


	//render 
	void drawInstruction(sf::RenderWindow* window);

	void runningInstruction(sf::RenderWindow* window, sf::Event& ev);
};