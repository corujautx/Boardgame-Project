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



template <class T>
class Board {
private:
	int m_columns, m_lines;
	std::vector< std::vector<T> > matrix;
public:
	Board(int, int);
	~Board();

	void placeTile(unsigned char, int, T);
	T getTileAt(unsigned char, int);
	std::vector<T> getAdjacent(unsigned char, int);
	bool isLegal(unsigned char column, int line);
	bool isValid(unsigned char column, int line);
	std::vector<T> getFilledAdjacent(unsigned char column, int line);
};



#endif /* BOARD_H_ */

