#include <iostream>
#include <chrono>
#include <Windows.h>
#include "game_of_life.h"
using namespace std;

int main() {

	srand(time(nullptr));
	game_of_life the_game;
	bool dalje = true;
	do {
		the_game.iscrtaj();
		Sleep(2000);
		the_game.sljedeca_generacija();

		if (dalje) the_game.clearScreen();
	} while (dalje);

	return 0;
}