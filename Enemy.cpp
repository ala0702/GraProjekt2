#include "Enemy.h"
#include <ctime>
#include "game.h"


void Enemy::initiateVariables()
{
	this->spawnTimerMaxEnemies = 30.f;
	this->spawnTimerEnemies = this->spawnTimerMaxEnemies;
	this->maxEnemies = 7;
	this->health = 10;

}
//private functions
void Enemy::initiateEnemyShape()
{

	this->EnemyShape.setRadius(rand() % 30 + 10.f);
	this->EnemyShape.setFillColor(sf::Color::Color(255,0,0, 220));
	this->EnemyShape.setOutlineThickness(4);
	this->EnemyShape.setOutlineColor(sf::Color::Red);
	
}

Enemy::Enemy()
{
	this->initiateEnemyShape();
	this->initiateVariables();
}

Enemy::~Enemy()
{
}


void Enemy::spawnEnemies(sf::RenderWindow* window)
{
	/*
		return void
		Spawns enemies
		Adds enemy to the vector.
	*/

	this->EnemyShape.setRadius(rand() % 30 + 10.f);
	this->EnemyShape.setFillColor(sf::Color::Color(255, 0, 0, 220));
	this->EnemyShape.setOutlineThickness(4);
	this->EnemyShape.setOutlineColor(sf::Color::Red);
	this->EnemyShape.setPosition(
		static_cast<float>(rand() % static_cast<int>(window->getSize().x - EnemyShape.getRadius())),
		0.f
	);
	this->enemies.push_back(this->EnemyShape);

}

//todo
void Enemy::update(sf::RenderWindow* window)
{
	
	if (this->enemies.size() < this->maxEnemies)
	{
		std::cout << "udalo sie" <<std:: endl;
		if (this->spawnTimerEnemies >= this->spawnTimerMaxEnemies)
		{
			//Spawn the enemy and reset the timer
			this->spawnEnemies(window);
			this->spawnTimerEnemies = 0.f;
		}
		else
			this->spawnTimerEnemies += 1.f;
	}
	//moving

	for (int i = 0; i < this->enemies.size(); i++)
	{
		enemies[i].move(0.f, 3.f);
		if (this->enemies[i].getPosition().y > window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health--;
			std::cout << health << std::endl;

		}
		//collision with player


	}
	//collision


}

void Enemy::render(sf::RenderTarget* target)
{
	for (int i=0; i<enemies.size(); i++)
	{
		target->draw(enemies[i]);
	}

}
