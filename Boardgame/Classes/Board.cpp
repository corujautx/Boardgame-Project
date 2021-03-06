/*
 * Board.cpp
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#include "Board.h"

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

template <class T>
bool Board<T>::isLegal(unsigned char column, int line){
	if((column >= 'A') && (column < (m_columns + 'A')) && (line >= 0) && (line < m_lines))
	{
		if(getTileAt(column,line) == T())
			return true;
		else
			return false;
	}
	else
		return false;
}

template <class T>
bool Board<T>::isValid(unsigned char column, int line){
	if((column >= 'A') && (column < (m_columns + 'A')) && (line >= 0) && (line < m_lines))
		return true;
	else
		return false;
}

template<class T>
std::vector<T> Board<T>::getFilledAdjacent(unsigned char column, int line){
	std::vector<T> filled;

	if(this->isValid(column, line)){
		std::vector<T> adj(this->getAdjacent(column, line));

		for(int i = 0; i< adj.size(); ++i){
			if(adj[i] != T())
				filled.push_back(adj[i]);
		}
	}
	return filled;
}

template <class T2>
std::ostream& operator<<(std::ostream& out, const Board<T2>& board)
{
	for(int i = 0 ; i < board.m_lines; i++)
	{
		for(int j = 0; j < board.m_columns ; j++)
		{
			if(board.matrix[j][i] == (char)0)
				out << " .";
			else
				out << board.matrix[j][i] << ".";
		}
		out << std::endl;
	}
	return out;
}

template <class T>
int Board<T>::getColumns()
{
	return m_columns;
}

template <class T>
int Board<T>::getRows()
{
	return m_lines;
}

template <class T>
int Board<T>::mergeGroups(T acquiredGroupIdentifier, T acquiringGroupIdentifier)
{
	int count = 0;
	for(int i=0; i < m_columns; i++)
	{
		for(int j=0; j < m_lines; j++)
		{
			if(matrix[i][j] == acquiredGroupIdentifier)
			{
				matrix[i][j] = acquiringGroupIdentifier;
				count++;
			}
		}
	}
	return count;
}
