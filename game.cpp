#include "game.h"
#include "Enemy.h"


void game::initiateEnemyShape()
{
	this->EnemyShape.setRadius(rand() % 30 + 10.f);
	this->EnemyShape.setFillColor(sf::Color::Color(255, 0, 0, 220));
	this->EnemyShape.setOutlineThickness(4);
	this->EnemyShape.setOutlineColor(sf::Color::Red);
}

void game::initiateFriendShape()
{
	this->FriendShape.setRadius(rand() % 30 + 10.f);
	this->FriendShape.setFillColor(sf::Color::Color(255, 0, 0, 220));
	this->FriendShape.setOutlineThickness(4);
	this->FriendShape.setOutlineColor(sf::Color::Color(rand() % 150, rand() % 254, rand() % 240));
}

void game::ustawiniaCzcionki()
{
	if (this->font.loadFromFile("zasob/czcionki/menu.ttf"))
	{
		std::cout << "nie udalo sie pobrac czcionki" << std::endl;
	}
}

void game::ustawieniaTekstu()
{
	this->text.setFont(this->font);  //nadajemy tekstowi czcionke aby wyswietlil sie na ekranie
	this->text.setCharacterSize(40);
	this->text.setLetterSpacing(2);
	this->text.setFillColor(sf::Color::Color(230, 245, 50, 160));
	this->text.setString("nic na razie");
}

void game::initiateVAriables()
{
	//logic
	this->points = 0;
	this->spawnTimerMaxEnemies = 30.f;
	this->spawnTimerEnemies = this->spawnTimerMaxEnemies;
	this->maxEnemies = 10;
	this->health = 10;
	this->spawnTimerMaxFriends = 20.f;
	this->spawnTimerFriends= this->spawnTimerMaxFriends;
	this->maxFriends = 20;
	
	
	
}

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
	this->initiateVAriables();
	this->initiateEnemyShape();
	this->initiateFriendShape();
}

//destructor
game::~game()
{
	delete this->window;
}

//ENEMIES FUNCTIONS
void game::spawnEnemies(sf::RenderWindow* window)
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
void game::updateEnemies(sf::RenderWindow* window)
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
			enemies[i].move(0.f, 3.5);
		else if (this->points < 200)
			enemies[i].move(0.f, 3.8);
		else if (this->points < 300)
			enemies[i].move(0.f, 4.f);
		else
			enemies[i].move(0.f, 4.2);


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
			std::cout << health << std::endl;
		}
	}
}
void game::renderEnemies(sf::RenderTarget* target) //rendering enemies
{
	for (int i = 0; i < enemies.size(); i++)
	{
		target->draw(enemies[i]);
	}
}

//FRIENDS FUNCTIONS
void game::spawnFriends(sf::RenderWindow* window)
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

void game::updateFriends(sf::RenderWindow* window)
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
		if(this->points<50)
		friends[i].move(0.f, 3.f);
		else if(this->points<100)
		friends[i].move(0.f, 3);
		else if (this->points < 150)
			friends[i].move(0.f, 3.4);
		else if (this->points < 200)
			friends[i].move(0.f, 3.6);
		else if (this->points < 250)
			friends[i].move(0.f, 3);
		else if (this->points < 300)
			friends[i].move(0.f, 4.f);
		else if (this->points < 350)
			friends[i].move(0.f, 3.2);
		else if (this->points < 400)
			friends[i].move(0.f, 3.4);
		else if (this->points < 450)
			friends[i].move(0.f, 3);
		else
			friends[i].move(0.f, 4.8);
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
			this->points += 10;
			std::cout << points << std:: endl;
		}


	}

}

void game::renderFriends(sf::RenderTarget* target)
{
	for (int i = 0; i < friends.size(); i++)
	{
		target->draw(friends[i]);
	}
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
	this->Player.update(this->window);
	this->updateFriends(this->window);
	this->updateEnemies(this->window);
}
void game::render()
{
	this->window->clear(sf::Color::Color(200,200,200));

	//DRAWING OBJECTS
	this->Player.render(this->window);
	this->renderFriends(this->window);
	this->renderEnemies(this->window);

	//END OF DRAWING
	this->window->display();
}


//game loop
void game::running()
{
	while (this->window->isOpen())
	{
		this->pollEvent();
	    if (this->health > 0)
	    {
				this->update();
				this->render();
	    }
	}
}

