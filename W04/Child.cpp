/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "Child.h"
using namespace std;

namespace sdds{

Child::Child(string name, int age, const Toy* toys[], size_t count) :c_age{ age }, c_length_Toys{ count }, c_name{ name }
{
	c_array_Toys = new const Toy* [count];

	for (size_t i = 0; i < count; i++)
	{
		c_array_Toys[i] = new Toy(*toys[i]);
	}
}

size_t Child::size() const 
{
	return c_length_Toys;
}

std::ostream& operator<<(std::ostream& ostr, const Child& child) {

	static int CALL_INT = 1;
	ostr << "--------------------------" << endl;
	ostr << "Child " << CALL_INT << ": " << child.c_name << " " << child.c_age << " years old:" << endl;
	ostr << "--------------------------" << endl;
	if (child.c_array_Toys != nullptr) {
		for (size_t i = 0; i < child.size(); i++) {
			ostr << *child.c_array_Toys[i];
		}
	}
	else {
		ostr << "This child has no toys!" << endl;
	}
	ostr << "--------------------------" << endl;

	CALL_INT++;
	return ostr;
	
}

Child::Child(const Child& C) {
	operator=(C);
}

Child::Child(Child&& C) {
	operator=(move(C));
}

Child& Child::operator=(const Child& C) {
	
	if (this != &C) {

		for (size_t i = 0; i < c_length_Toys; i++) 
		{
			delete this->c_array_Toys[i];
		}
		delete[] this->c_array_Toys;

		c_name = C.c_name;
		c_age = C.c_age;
		c_length_Toys = C.c_length_Toys;

		c_array_Toys = new const Toy * [size()];

		for (size_t i = 0; i < C.c_length_Toys; i++)
		{
			c_array_Toys[i] = new Toy(*C.c_array_Toys[i]);
		}
	}
	return *this;
}

Child& Child::operator=(Child&& C) {

	if (this != &C) {

		for (size_t i = 0; i < c_length_Toys; i++) {
			delete this->c_array_Toys[i];
		}
		delete[] this->c_array_Toys;
	
		c_name = C.c_name;
		c_age = C.c_age;
		c_length_Toys = C.c_length_Toys;
		c_array_Toys = C.c_array_Toys;


	
		C.c_array_Toys = nullptr;
		C.c_name = "";
		C.c_age = 0;
		C.c_length_Toys = 0;
	}

	return *this;
}

Child::~Child() {
	for (size_t i = 0; i < c_length_Toys; i++) {
		delete this->c_array_Toys[i];
	}
	delete[] this->c_array_Toys;
	
}

}