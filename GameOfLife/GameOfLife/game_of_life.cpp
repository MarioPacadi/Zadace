#include "game_of_life.h"
#include<iostream>
#include<chrono>
using namespace std;

game_of_life::game_of_life()
{
	/*
	Živi organizam u æeliji preživljava u sljedeæoj generaciji ukoliko je broj njegovih susjeda dva ili tri.
	Živi organizam u æeliji umire u sljedeæoj generaciji ukoliko je broj njegovih susjeda manji od dva
	(zbog usamljenosti) ili veæi od tri (zbog prenaseljenosti).
	U praznoj æeliji se raða novi organizam ukoliko se u toèno tri njene susjedne æelije nalaze živi organizmi
	Neka prilikom inicijalizacije igre postoji 25% šanse da æe u æeliji biti živi organizam.
	*/

	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{
			_generacija[x][y] = slucajna_vrijednost(25);
			_sljedeca_generacija[x][y] = false;
		}
	}
}

int game_of_life::genRand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

bool game_of_life::slucajna_vrijednost(int sansa)
{
	if (genRand(1, 100) <= sansa) return true;
	else
		return false;
}

void game_of_life::celija_zauzeta()
{
	sljedeca_generacija();

	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{
			int alive = 0;
			for (int z = -1; z < 2; z++)
			{
				for (int q = -1; q < 2; q++)
				{
					if (x + z >= REDAKA || y + q >= STUPACA) continue;
					if (x + z < 0 || y + q < 0) continue;
					if (!(z == 0 && q == 0))
					{
						if (_sljedeca_generacija[x + z][y + q])
						{
							++alive;
						}
					}
				}
			}
			if (alive < 2)
			{
				_generacija[x][y] = false;
			}
			else if (alive == 3)
			{
				_generacija[x][y] = true;
			}
			else if (alive > 3)
			{
				_generacija[x][y] = false;
			}
		}
	}

}

void game_of_life::sljedeca_generacija()
{
	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{
			_sljedeca_generacija[x][y] = _generacija[x][y];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int x = 1; x < REDAKA; x++)
	{
		for (int y = 1; y < STUPACA; y++)
		{
			if (_generacija[x][y] == true)
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}

	celija_zauzeta();
}

void game_of_life::clearScreen()
{
	system("cls");
}