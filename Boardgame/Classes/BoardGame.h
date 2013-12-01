/*
 * BoardGame.h
 *
 *  Created on: Dec 1, 2013
 *      Author: Albert
 */

#ifndef BOARDGAME_H_
#define BOARDGAME_H_

#include <map>
#include <string>
#include "Board.h"
#include "Group.h"
#include "Position.h"
using namespace std;

template <class T>
class BoardGame {

private:
	Board<T> board;
	map<T, Group*> groups;

public:
	BoardGame(int,int);
	virtual ~BoardGame();
	void PlayAt(Position pos);
};

#endif /* BOARDGAME_H_ */
