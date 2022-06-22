#include "Game.h"


using namespace std;
using namespace sf;

int main()
{

	// time setting
	srand(static_cast<unsigned>(time(NULL)));

	Game game;
	game.whatToDo();

	return 0;
}