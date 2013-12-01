/*
 * BoardGame.cpp
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#include "BoardGame.h"

template <class T>
BoardGame<T>::BoardGame(int row, int col):
	board(row,col)
{
	groups.insert(std::pair<T,Group*>(0,Group::getDummy()));
}


