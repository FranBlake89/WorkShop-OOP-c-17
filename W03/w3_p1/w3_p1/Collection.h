/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
//This module represents a family of collections of elements of any data type 
//(for example, collection of ints, or collection of Pairs, etc.).

template <typename T, size_t CAPACITY>

class Collection
{
	size_t m_size{};
	T m_items[CAPACITY]{};
	T dummyObj{};

public:
	Collection() : size(0) {};
	int size() { return m_size; }
	virtual ~Collection() {};
	void display(std::ostream& os = std::cout) const;


};

