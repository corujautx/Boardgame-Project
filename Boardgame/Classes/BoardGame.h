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
	Boardgame::Board<T> board;
	map<T, Boardgame::Group*> groups;

public:
	BoardGame(int,int);
	virtual ~BoardGame();
	void PlayAt(Position pos);
};


BoardGame<char>::BoardGame(int row, int col):
	board(row,col), groups(){
	groups.insert(std::pair<char,Boardgame::Group*>(0,Boardgame::Group::getDummy()));
}








#endif /* BOARDGAME_H_ */
