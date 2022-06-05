#pragma once

#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>\
#include "game.h"

class Enemy
{
private:
	sf::CircleShape EnemyShape;
	std::vector<sf::CircleShape> enemies;
	

	float spawnTimerMaxEnemies; //co ile beda pojawiac sie rzeczy na ekranie (im mniej tym szycbiej sie pojawiaja)
	float spawnTimerEnemies;
	float maxEnemies; //maximum of enemies 
	int health;

	//private functions
	void initiateVariables();
	void initiateEnemyShape();

public:
	Enemy();
	~Enemy();
	void spawnEnemies(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);
	void render(sf::RenderTarget* target);



};

