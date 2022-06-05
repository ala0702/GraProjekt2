#include "game.h"
#include "Menu.h"
#include <ctime>

using namespace std;
using namespace sf;

int main()
{
	//RenderWindow window(VideoMode(200, 200), "SFML works!");
	////CircleShape shape(100.f);
	////shape.setFillColor(Color::Green);
	//Menu menu(window.getSize().x, window.getSize().y);

	//while (window.isOpen())
	//{
	//	Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == Event::Closed)
	//		{
	//			window.close();
	//		}
	//	}

	//	window.clear();
	//	menu.draw(window);
	//	//window.draw(shape);
	//	window.display();
	//}


	// time setting
	srand(static_cast<unsigned>(time(NULL)));

	game game;
	game.running();

	return 0;
}