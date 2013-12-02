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
	char m_symbol;
	std::string m_name;
	int m_age;
	int m_size;
public:
	//constructors, destructors, assignment operator, copy constructor
	Group() : m_symbol(), m_name(), m_age(0), m_size(0) {};
	Group(char symbol, std::string name, int age) : m_symbol(symbol), m_name(name), m_age(age), m_size(1) {};

	//class methods
	char getSymbol();
	std::string getName();
	int getAge();
	int getSize() { return m_size; }
	void increaseSizeBy(int increased) { m_size += increased; }
	static Group getDummy();

	friend bool operator<(const Group& a, const Group& b)
	{
		if(a.m_size < b.m_size)
		{
			return true;
		}
		else if(a.m_size == b.m_size)
		{
			return a.m_age > b.m_age;
		}
		return false;
	}
};


#endif /* GROUP_H_ */
