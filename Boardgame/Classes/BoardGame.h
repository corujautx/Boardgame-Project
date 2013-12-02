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

class BoardGame {

private:
	char m_symbol_counter;
	Board<char> board;
	map<char, Group> groups;

public:
	BoardGame(int, int);
	int PlayAt(Position, string, int);
	friend ostream& operator<<(ostream&, const BoardGame&);
};

#endif /* BOARDGAME_H_ */
