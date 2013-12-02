/*
 * Position.h
 *
 *  Created on: Dec 1, 2013
 *      Author: Albert
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {

private:
	int row;
	char col;

public:
	Position(char c,int i) : row(i), col(c){};
	int getRow();
	char getCol();
};

#endif /* POSITION_H_ */
