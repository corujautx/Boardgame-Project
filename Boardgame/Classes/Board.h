/*
 * Board.h
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>

namespace Boardgame{

template <class T>
class Board {
private:
	int m_columns, m_lines;
	std::vector< std::vector<T> > matrix;
public:
	Board(int, int);
	virtual ~Board();

	void placeTile(unsigned char, int, T);
	T getTileAt(unsigned char, int);
	std::vector<T> getAdjacent(unsigned char, int);
};

} /* namespace Boardgame */

#endif /* BOARD_H_ */

