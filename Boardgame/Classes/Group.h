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

class Group {
private:
	static char m_symbol_counter;
	char m_symbol;
	std::string m_name;
	int m_age;
public:
	//constructors, destructors, assignment operator, copy constructor
	Group() : m_symbol(), m_name(), m_age() {};
	Group(char symbol, std::string name, int age) : m_symbol(symbol), m_name(name), m_age(age) {};

	//class methods
	char getSymbol();
	std::string getName();
	int getAge();
	char incCounter();
	static Group* getDummy();
};

#endif /* GROUP_H_ */
