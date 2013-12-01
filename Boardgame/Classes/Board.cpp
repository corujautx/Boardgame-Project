/*
 * Board.cpp
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#include "Board.h"
#include <string>

template <class T>
Board<T>::Board(int m, int n) : m_columns(m), m_lines(n) {
	for(int i = 0; i < m; i++)
	{
		matrix.push_back(std::vector<T>(n));
	}
}

template <class T>
Board<T>::~Board()
{
	matrix.clear();
}

template <class T>
void Board<T>::placeTile(unsigned char column, int line, T value)
{
	if( (column >= 'A' && column < (m_columns + 'A')) && (line >= 0 && line < m_lines))
	{
		matrix[column - 'A'][line] = value;
	}
	else
	{
		throw std::string("Board<T>::placeTile : index out of boundaries");
	}
}

template <class T>
T Board<T>::getTileAt(unsigned char column, int line)
{
	if ( (column >= 'A' && column < (m_columns + 'A')) && (line >= 0 && line < m_lines))
	{
		return matrix[column - 'A'][line];
	}
	else
	{
		throw std::string("Board<T>::getTileAt : index out of boundaries");
	}
}

template<class T>
std::vector<T> Board<T>::getAdjacent(unsigned char column, int line)
{
	std::vector<T> adjacent;
	if((column >= 'A') && (column < (m_columns + 'A')) && (line >= 0) && (line < m_lines))
	{
		//only if there's more than 1 line
		if(m_lines >= 2)
		{
			if(line > 0)
				adjacent.push_back(matrix[column - 'A'][line - 1]); // push top tile
			if(line < matrix[0].size() -1)
				adjacent.push_back(matrix[column - 'A'][line + 1]); // push bottom tile
		}
		//only if there's more than 1 column
		if(m_columns >= 2)
		{
			if(column > 'A')
				adjacent.push_back(matrix[column - 'A' - 1][line]); // push left tile
			if((int)(column - 'A') < matrix.size() - 1)
				adjacent.push_back(matrix[column - 'A' + 1][line]); // push right tile
		}
	}
	else
	{
		throw std::string("Board<T>::getAdjacent : index out of boundaries");
	}

	return adjacent;
}

//relevant construction
template class Board<std::string>;
