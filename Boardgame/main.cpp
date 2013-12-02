/*
 * main.cpp
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#include <iostream>
#include <cstdlib>
#include "Classes/BoardGame.h"
#include <string>
using namespace std;

int main()
{
	int turn = 0;
	int countP1 = 0; int countP2 = 0;

	BoardGame bg(8,8);
	while((countP1 < 41) && (countP2 < 41))
	{
		cout << "\nTurn: " << turn/2 + 1 << "Score: " << countP1 << " " << countP2 << endl;
		cout << ((turn % 2) == 0 ? "Player 1" : "Player 2") << " turn" << endl;
		cout << "\n" << bg << "\n" << endl;

		char col;
		int row;

		cin >> col >> row;

		try
		{
			int count = bg.PlayAt(Position(col, row), (turn % 2) == 0 ? "Player 1" : "Player 2", turn);
			if(turn%2 == 0)
			{
				countP1 += count;
			}
			else
			{
				countP2 += count;
			}
		}
		catch(string& exception)
		{
			cout << "Invalid play! (Lost your turn)\n" << endl;
		}

		turn++;
	}

	cout << "Game over!" << endl;
	cout << bg << endl;

	cout << (countP1 > countP2 ? "Player 1 wins!" : "Player 2 wins") << endl;

	system("pause");

	return 0;
}



