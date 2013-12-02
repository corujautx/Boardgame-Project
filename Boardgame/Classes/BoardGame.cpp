/*
 * BoardGame.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: Albert
 */
#include "BoardGame.h"
#include <set>

BoardGame::BoardGame(int columns, int rows): m_symbol_counter('A'), board(columns, rows)
{
	groups.insert(std::pair<char,Group>(char(), Group::getDummy()));
}

int BoardGame::PlayAt(Position pos, string name, int step)
{
	char column = pos.getCol();
	int line = pos.getRow();
	if(!board.isLegal(column, line))
	{
		throw std::string("Illegal Move");
	}

	vector<char> filled(board.getFilledAdjacent(column,line));
	if(filled.size() == 0)
	{
		groups.insert(std::pair<char, Group>(m_symbol_counter, Group(m_symbol_counter, name, step)));
		board.placeTile(column, line, m_symbol_counter);
		++m_symbol_counter;
		return 1;
	}
	else
	{
		set<Group> groupsFilled;
		for(unsigned int i = 0; i < filled.size(); i++)
		{
			groupsFilled.insert(groups[filled[i]]);
		}

		vector<Group> finalGroup;
		copy(groupsFilled.begin(), groupsFilled.end(), back_inserter(finalGroup));

		cout << finalGroup.rbegin()->getSymbol() << endl;

		board.placeTile(column, line, (finalGroup.rbegin())->getSymbol());

		int countReplace = 1;
		for(vector<Group>::iterator it = finalGroup.begin(); it != finalGroup.end() - 1; it++)
		{
			countReplace += board.mergeGroups(it->getSymbol(), (finalGroup.rbegin())->getSymbol());
		}

		groups[finalGroup.rbegin()->getSymbol()].increaseSizeBy(countReplace);
		return countReplace;
	}
}

ostream& operator<<(ostream& os, const BoardGame& boardGame)
{
	os << boardGame.board << endl;
	return os;
}


