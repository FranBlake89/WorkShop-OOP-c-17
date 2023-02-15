/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/
#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

#include "Toy.h"



namespace sdds {

	class Child
	{
	private:
		const sdds::Toy** c_array_Toys{};
		int c_age{};
		size_t c_length_Toys{};
		std::string c_name{};

	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;

		//rule of five
		Child(const Child& V);
		Child(Child&& V);
		Child& operator=(const Child& V);
		Child& operator=(Child&& V);
		virtual ~Child();

		friend std::ostream& operator<<(std::ostream& ostr, const Child& V);

	};
	
}


