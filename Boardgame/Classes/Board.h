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
#include <string>

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
	int mergeGroups(T, T);

	template <class T2> friend std::ostream& operator<<(std::ostream&, const Board<T2>&);

	int getColumns();
	int getRows();
};

//relevant construction
template class Board<std::string>;
template class Board<char>;


#endif /* BOARD_H_ */

