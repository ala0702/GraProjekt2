#pragma once

#include <vector>
#include "Player.h"
#include "Menu.h"
#include "Instruction.h"
#include <ctime> 
#include <sstream> // allows to make strings

class Game :public Menu, public Instruction
{
private:

	//window and event
	sf::VideoMode vm; //holds the information about height and wight of the window
	sf::RenderWindow* window; //
	sf::Event event; //

	//menu 
	Menu menu;

	//instruction
	Instruction instruction;

	
	//player
	Player Player;

	//logic of the game
	unsigned points;
	int health;

	bool getLeaveGame;

	
	//resource *font*text*
	sf::Font font;
	sf::Font fontEndGame;
	sf::Text text;
	sf::Text textEndGame;

	//Circle shape enemies
	sf::CircleShape EnemyShape;
	std::vector<sf::CircleShape> enemies;
	float spawnTimerMaxEnemies; //co ile beda pojawiac sie rzeczy na ekranie (im mniej tym szycbiej sie pojawiaja)
	float spawnTimerEnemies;
	float maxEnemies; //maximum of enemies 
	

	//Circle shape friends
	sf::CircleShape FriendShape;
	std::vector<sf::CircleShape> friends;
	float spawnTimerMaxFriends; //co ile beda pojawiac sie rzeczy na ekranie (im mniej tym szycbiej sie pojawiaja)
	float spawnTimerFriends;
	float maxFriends; //maximum of enemies 


	//private functions (initialize things)
	void initiateVAriables();
	void initiateWindow();
	void initiateEnemyShape();
	void initiateFriendShape();
	void ustawiniaCzcionki();
	void initiateFontEndGame();
	void initiateTextEndGame();
	void ustawieniaTekstu();



public:
	//constructor and destructor
	Game();
	~Game();


	//enemies functions
	
	void spawnEnemies(sf::RenderWindow* window);
	void updateEnemies(sf::RenderWindow* window);
	void renderEnemies(sf::RenderTarget* target);

	//friends functions
	void spawnFriends(sf::RenderWindow* window);
	void updateFriends(sf::RenderWindow* window);
	void renderFriends(sf::RenderTarget* target);


	//accessors

	//text
	void updateText();
	void renderText(sf::RenderTarget* target);

	void updateTextEndGame();

	//update
	void pollEvent(); //checks events

	//function that erase left objects
	void eraseObjectEndGame();

	//main update and render
	void update();
	void render();

	//main runnning game
	void pollEventAfterGame();
	void running();


	//render right thing, menu, engine:))
	void whatToDo();


};