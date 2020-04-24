#pragma once

#include <iostream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	int genRand(int min, int max);
	bool slucajna_vrijednost(int sansa);
	void celija_zauzeta();

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
	void clearScreen();

};
