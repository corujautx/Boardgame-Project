/*
 * BoardGame.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: Albert
 */
#include "BoardGame.h"

template <class T>
BoardGame<T>::BoardGame(int row, int col):
	board(row,col)
{
	groups.insert(std::pair<T,Group*>(0,Group::getDummy()));
}

template <class T>
void BoardGame<T>::PlayAt(Position pos){
	try
	{
		if(!board.isLegal(pos.getCol(), pos.getRow()))
		{
			throw std::string("Illegal Move");
		}
	}
	catch(std::string& e)
	{
		cout << e << endl;
	}
}
