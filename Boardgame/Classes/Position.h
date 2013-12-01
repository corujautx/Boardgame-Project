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
	char row;
	int col;

public:
	Position(char c,int i) : row(c) , col(i){};
	char getRow();
	int getCol();
};

#endif /* POSITION_H_ */
