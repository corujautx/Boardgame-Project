/*
 * BoardGame.h
 *
 *  Created on: Dec 1, 2013
 *      Author: Albert
 */

#ifndef BOARDGAME_H_
#define BOARDGAME_H_


#include "Board.cpp"
#include "Group.h"
#include "Position.h"
#include <map>

using namespace std;

template <class T>
class BoardGame {

private:
	Board<T> board;
	map<T, Group*> groups;

public:
	BoardGame(int,int);
	void PlayAt(Position pos);
};

#endif /* BOARDGAME_H_ */
