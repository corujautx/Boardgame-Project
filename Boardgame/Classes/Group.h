/*
 * Group.h
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <iostream>
#include <string>

namespace Boardgame {

class Group {
private:
	char m_symbol;
	std::string m_name;
	int m_age;
public:
	//constructors, destructors, assignment operator, copy constructor
	Group(char symbol, std::string name, int age) : m_symbol(symbol), m_name(name), m_age(age) {};

	//class methods
	char getSymbol();
	std::string getName();
	int getAge();
};

} /* namespace Boardgame */

#endif /* GROUP_H_ */
