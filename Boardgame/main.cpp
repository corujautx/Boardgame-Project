/*
 * main.cpp
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#include <iostream>
#include "Classes/Board.h"
#include <string>
using namespace std;


int main()
{

	Boardgame::Board<string> A(10,10);

	A.placeTile('A',3,"Up");
	A.placeTile('C',3,"Down");
	A.placeTile('B',2,"Left");
	A.placeTile('B',4,"Right");
	A.placeTile('B',3,"Centre");

	cout << A.getTileAt('B',3)<< endl;
	cout << A.getTileAt('A',3)<< endl;
	cout << A.getTileAt('C',3)<< endl;
	cout << A.getTileAt('G',2)<< endl;
	cout << A.getTileAt('B',4)<< endl;
	return 0;
}



