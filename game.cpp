#include "Game.h"

//private functions

void Game::initiateEnemyShape()
{
	this->EnemyShape.setRadius(20.f);
	this->EnemyShape.setFillColor(sf::Color::Color(255, 0, 0, 220));
	this->EnemyShape.setOutlineThickness(4);
	this->EnemyShape.setOutlineColor(sf::Color::Red);
}

void Game::initiateFriendShape()
{
	this->FriendShape.setRadius(rand() % 30 + 10.f);
	this->FriendShape.setFillColor(sf::Color::Color(255, 0, 0, 220));
	this->FriendShape.setOutlineThickness(4);
	this->FriendShape.setOutlineColor(sf::Color::Color(rand() % 150, rand() % 254, rand() % 240));
}

void Game::ustawiniaCzcionki()
{
	if (this->font.loadFromFile("zasob/czcionki/TeleVision.ttf"))
	{
		
	}
}

void Game::initiateFontEndGame()
{
	if (this->fontEndGame.loadFromFile("zasob/czcionki/ok.ttf"))
	{
		
	}
}

void Game::initiateTextEndGame()
{
	this->textEndGame.setFont(this->fontEndGame);  //nadajemy tekstowi czcionke aby wyswietlil sie na ekranie
	this->textEndGame.setCharacterSize(42);
	this->textEndGame.setLetterSpacing(1);
	this->textEndGame.setFillColor(sf::Color::Color(0,0,0, 255));
	this->textEndGame.setLineSpacing(1);
	this->textEndGame.setPosition(sf::Vector2f(60.f, 200.f));
	this->textEndGame.setString("pusto");

}

void Game::ustawieniaTekstu()
{
	this->text.setFont(this->font);  //nadajemy tekstowi czcionke aby wyswietlil sie na ekranie
	this->text.setCharacterSize(40);
	this->text.setLetterSpacing(2);
	this->text.setFillColor(sf::Color::Color(0, 0, 0, 120));
	this->text.setString("nic na razie");
}

void Game::initiateVAriables()
{
	//logic
	this->points = 0;
	this->spawnTimerMaxEnemies = 25.f;
	this->spawnTimerEnemies = this->spawnTimerMaxEnemies;
	this->maxEnemies = 10;
	this->health = 10;
	this->spawnTimerMaxFriends = 10.f; //the lower number the faster spawn of objects = more objects on the screen
	this->spawnTimerFriends= this->spawnTimerMaxFriends;
	this->maxFriends = 20;
	this->getLeaveGame = false;

}

void Game::initiateWindow()
{
	this->vm = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->vm, "PROJECT GAME", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

//constructor
Game::Game()
{
	this->initiateWindow(); 
	this->initiateVAriables();
	this->initiateEnemyShape();
	this->initiateFriendShape();
	this->ustawiniaCzcionki();
	this->initiateFontEndGame();
	this->initiateTextEndGame();
	this->ustawieniaTekstu();
	/*this->spawnEnemies(this->window);
	this->spawnFriends(this->window);*/
}

//destructor
Game::~Game()
{
	delete this->window;
}

//ENEMIES FUNCTIONS
void Game::spawnEnemies(sf::RenderWindow* window)
{
	/*
		return void
		Spawns enemies
		Adds enemy to the vector.
	*/

	this->EnemyShape.setRadius(20.f);
	this->EnemyShape.setFillColor(sf::Color::Color(255, 0, 0, 220));
	this->EnemyShape.setOutlineThickness(4);
	this->EnemyShape.setOutlineColor(sf::Color::Red);
	this->EnemyShape.setPosition(
		static_cast<float>(rand() % static_cast<int>(window->getSize().x - EnemyShape.getRadius())),
		0.f
	);
	this->enemies.push_back(this->EnemyShape);
}

void Game::updateEnemies(sf::RenderWindow* window)
{
	if (this->enemies.size() < this->maxEnemies)
	{
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
		//moves to down
		if (this->points < 100)
			enemies[i].move(0.f, 2.6);
		else if (this->points < 200)
			enemies[i].move(0.f, 2.8);
		else if (this->points < 300)
			enemies[i].move(0.f, 3.f);
		else
			enemies[i].move(0.f, 3.2);

		//erase when touch the bottom of the window
		if (this->enemies[i].getPosition().y > window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);

		}
		//collision with player
		//*remove
		//*healt-1
		if (this->Player.Rshape.getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))
		{
			this->enemies.erase(enemies.begin() + i);
			this->health--;
		}
	}
}
void Game::renderEnemies(sf::RenderTarget* target) //rendering enemies
{
	for (int i = 0; i < enemies.size(); i++)
	{
		target->draw(enemies[i]);
	}
}

//FRIENDS FUNCTIONS
void Game::spawnFriends(sf::RenderWindow* window)
{
	/*
		return void
		Adds friends to the vector.
	*/

	this->FriendShape.setRadius(rand() % 5 + 7.f);
	this->FriendShape.setFillColor(sf::Color::Color(rand()%150, rand()%254, rand()%240));
	this->FriendShape.setOutlineThickness(4);
	
	this->FriendShape.setPosition(
		static_cast<float>(rand() % static_cast<int>(window->getSize().x - FriendShape.getRadius())),
		0.f
	);

	this->friends.push_back(this->FriendShape);
}

void Game::updateFriends(sf::RenderWindow* window)
{
	if (this->friends.size() < this->maxFriends)
	{
		
		if (this->spawnTimerFriends >= this->spawnTimerMaxFriends)
		{
			//Spawn the enemy and reset the timer
			this->spawnFriends(window);
			this->spawnTimerFriends = 0.f;
		}
		else
			this->spawnTimerFriends += 1.f;
	}
	//moving

	for (int i = 0; i < this->friends.size(); i++)
	{
		//moves to down
		if(this->points<100)
		friends[i].move(0.f, 2.6);
		else if(this->points<150)
		friends[i].move(0.f, 2.7);
		else if (this->points < 200)
			friends[i].move(0.f, 2.8);
		else if (this->points < 300)
			friends[i].move(0.f, 2.9);
		else if (this->points < 350)
			friends[i].move(0.f, 3.1);
		else if (this->points < 450)
			friends[i].move(0.f, 3.3 );
		else if (this->points < 550)
			friends[i].move(0.f, 3.4);
		else if (this->points < 650)
			friends[i].move(0.f, 3.5);
		else if (this->points < 750)
			friends[i].move(0.f, 3.6);
		else
			friends[i].move(0.f, 3.8);
		//erase when touch the bottom of the window
		if (this->friends[i].getPosition().y > window->getSize().y)
		{
			this->friends.erase(this->friends.begin() + i);
		}
		//collision with player
		//*remove
		//*points+10

		if (this->Player.Rshape.getGlobalBounds().intersects(this->friends[i].getGlobalBounds()))
		{
			this->friends.erase(friends.begin() + i);
			this->points += 5;
		}
	}
}

void Game::renderFriends(sf::RenderTarget* target)
{
	for (int i = 0; i < friends.size(); i++)
	{
		target->draw(friends[i]);
	}
}


//text functions
void Game::updateText()
{
	std::stringstream ss;
	ss << "points : " << this->points << "\n" << "health : " << this->health;
	this->text.setString(ss.str());
}

void Game::renderText(sf::RenderTarget* target)
{
	target->draw(this->text);
}

void Game::updateTextEndGame()
{
	std::stringstream zz;
	zz << "                  GAME OVER" << "\n" << "          YOUR SCORE  ->  " << this->points << "\n" << "\n"<< " Press 'k' to return to the menu";
	this->textEndGame.setString(zz.str());
}


//public functions:

void Game::pollEvent()
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
			if (this->event.key.code == sf::Keyboard::K)
			{

			}
			if (this->event.key.code == sf::Keyboard::Enter)
			{
				if (this->menu.getSelectedItem(selectedItem) == 0)
				{
					this->running();
				}

			    if(this->menu.getSelectedItem(selectedItem) == 1)
				{
					this->runningInstruction(this->window, event);
				}

			    if (this->menu.getSelectedItem(selectedItem) == 2)
				{
					this->window->close();
				}
			}				break;
		}
	}
}

//delete letft objects from the window 
void Game::eraseObjectEndGame()
{
	while (enemies.begin() != enemies.end() )
	{
		enemies.erase(enemies.begin());
	}

	while (friends.begin() != friends.end())
	{
		friends.erase(friends.begin());
	}
}

	//main functions 
// *update
// *render
// *running the game
void Game::update()
{
	this->Player.update(this->window);
	this->updateFriends(this->window);
	this->updateEnemies(this->window);
	this->updateTextEndGame();
	this->updateText();
}

void Game::render()
{
	this->window->clear(sf::Color::Color(200,200,200));

	//DRAWING OBJECTS
	this->Player.render(this->window);
	this->renderFriends(this->window);
	this->renderEnemies(this->window);
	this->renderText(this->window);
	this->window->draw(this->text);
	if (this->health <= 0)
	{
		this->window->draw(this->textEndGame);
	}

	//END OF DRAWING
	this->window->display();
}

void Game::pollEventAfterGame()
{
	while (window->pollEvent(this->event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			if (event.key.code == sf::Keyboard::K)
			{
				this->getLeaveGame = true;
			}
			break;
		}
	}
}

//game loop
void Game::running()
{
	while (this->window->isOpen() && this->getLeaveGame==false)
	{
		if (this->health > 0)
		{
			this->pollEvent();
			this->update();
			this->render();
		}

		if (this->health <= 0)
		{
			this->updateTextEndGame();
			this->render();
			this->pollEventAfterGame();
		}
	}
	this->eraseObjectEndGame();
	this->initiateVAriables();
}

//main loop 
//*shows menu
//*you can open the game and instruction 
void Game::whatToDo()
{
	while(this->window->isOpen() )
	{
		this->pollEvent();
		this->updateMenu(this->window);
		
		this->window->clear(sf::Color::Color(200, 200, 200));
		this->drawMenu(this->window);
		//END OF DRAWING
		this->window->display();
	}
}