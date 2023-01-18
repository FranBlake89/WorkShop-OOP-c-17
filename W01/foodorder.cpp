/*
   ---------------------------------------
Name:		Francisco Castillo
Seneca Id:	148904212
e-mail:		fcastillo-rojas1@myseneca.ca
Section:	NDD
   ---------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

#include "foodorder.h"
using namespace std;

double g_taxrate;
double g_dailydiscount;

namespace sdds {
	static int counter = 1;
}

void sdds::FoodOrder::display()
{
	if (isEmpty() ) {
		cout << counter++ << ". No Order" << endl;
	}
	else {
		cout << setw(2) << left << counter << ". "
			<< setw(10) << left << c_name << "|"
			<< setw(25) << left << c_descrip << "|"
			<< setw(12) << left << fixed << setprecision(2)
			<< c_price * (1 + g_taxrate) << "|";

		if (c_IsDaily) {
			cout << setw(13) << right << fixed << setprecision(2)
				 <<((c_price * (1 + g_taxrate)) - (g_dailydiscount)) << endl;
		}
		else {
			cout << endl;
		}
		counter++;
	}
	
	setEmpty();
}
bool sdds::FoodOrder::isEmpty()
{
	return c_name.empty();
}
sdds::FoodOrder::FoodOrder() {
	setEmpty();
}

void sdds::FoodOrder::setEmpty()
{
	c_order = '\0';
	c_name = {};
	c_descrip = {};
	c_IsDaily = false;
	c_price = -1;
}

void sdds::FoodOrder::read(std::istream& in)
{
	setEmpty();

	string name{};
	getline(in, name, ',');

	string desc {};
	getline(in, desc, ',');

	double price = -1;
	in >> price;

	in.ignore();

	char isDailySpecial{0};
	in >> isDailySpecial;

	if (!in.fail() ) {
		this->setFoodOrder(name, desc, price, isDailySpecial);
		//c_string() CONVERT STRING into CONST CHAR*
	}
}

void sdds::FoodOrder::setFoodOrder( string name, string descrip, double price, char daily)
{
	//Length Name
	size_t len{};

	//len = strlen(name);
	len = name.length();
	//Allocation Name
	if (len != '\0' && len > 2) {
		//c_name = new char[lenName + 1];
		//strncpy(c_name, name, lenName);
		if (len > lenName)
			c_name = name.substr(0, lenName);
		else c_name = name;
	}	
	else  std::cout << "* Error: The NAME has not been copied *" << std::endl;

	//Length Description
	//len = strlen(descrip);
	//Allocation Description 
	len = descrip.length();
	if (len != '\0' && len > 0) {
		//c_descrip = new char[lenDesc + 1];
		//strncpy(c_descrip, descrip, lenDesc);
		if (len > lenDesc)
			c_descrip = descrip.substr(0, lenName);
		else c_descrip = descrip;
	}
	else  std::cout << "* Error: The DESCRIPTION has not been copied *" << std::endl;

	//Allocation PRICE
	c_price = price;

	//Allocation IsDaily
	if (daily == 'y' || daily == 'Y')
		c_IsDaily = true;
	else if (daily == 'n' || daily == 'N')
		c_IsDaily = false;
	else  std::cout << "* Error: IsDAILY has not been copied *" << std::endl;

}