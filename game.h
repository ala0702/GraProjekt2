#pragma once
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "player.h"

class game
{
private:
	//window and event
	sf::VideoMode vm; //holds the information about height and wight of the window
	sf::RenderWindow* window; //
	sf::Event event; //

	//player
	player Player;

	//logic of the game
	unsigned points;
	int health;

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


public:
	//constructor and destructor
	game();
	~game();


	//enemies functions
	
	void spawnEnemies(sf::RenderWindow* window);
	void updateEnemies(sf::RenderWindow* window);
	void renderEnemies(sf::RenderTarget* target);

	//friends functions
	void spawnFriends(sf::RenderWindow* window);
	void updateFriends(sf::RenderWindow* window);
	void renderFriends(sf::RenderTarget* target);


	//accessors

	//update
	void pollEvent(); //checks events

	//main update and render
	void update();
	void render();

	//main runnning game, engine;))
	void running();

};

