/*
 * Group.cpp
 *
 *  Created on: 01/12/2013
 *      Author: Vitor
 */

#include "Group.h"


char Group::m_symbol_counter = 'A';


char Group::getSymbol()
{
	return m_symbol;
}

std::string Group::getName()
{
	return m_name;
}

int Group::getAge()
{
	return m_age;
}

Group* Group::getDummy(){
	return new Group();
}
