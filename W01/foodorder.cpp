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
#include <iostream>
#include <iomanip>

#include "foodorder.h"
using namespace std;

double g_taxrate;
double g_dailydiscount;

void sdds::FoodOrder::display()
{
	if (strlen(c_name) < 2) {
		cout << counter++ << ". No Order" << endl;
	}
	else {
		cout << setw(2) << left << counter << ". "
			<< setw(10) << left << c_name << "|"
			<< setw(25) << left << c_descrip << "|"
			<< setw(12) << left << fixed << setprecision(2) << c_price * (1 + g_taxrate) << "|";
		if (c_IsDaily) {
			cout << setw(13) << right << fixed << setprecision(2) << c_price * (1 + g_taxrate) * (1 - g_dailydiscount) << endl;
		}
		else {
			cout << endl;
		}
		counter++;
	}

}
/*
void sdds::FoodOrder::setFoodOrder( string name, string descrip, double price, char daily)
{

	
//Allocation Order
//	if (daily == 'i' || daily == 'I')
//		this->c_IsDaily = 'I';
//	else if (daily == 'd' || daily == 'D')
//		this->c_IsDaily = 'D';
//	else  std::cout << "* Error: IsDAILY has not been copied *" << std::endl;

//Length Name
	int len = name.length();
	//Allocation Name
	if (len != '\0' && len > 2)
		strncpy(this->c_name, name.c_str(), lenName);
	//c_string() CONVERT STRING into CONST CHAR*
	else  std::cout << "* Error: The NAME has not been copied *" << std::endl;

//Length Description
	len = descrip.length();
	//Allocation Description 
	if (len != '\0' && len > 0)
		strncpy(this->c_descrip, descrip.c_str(), lenDesc);
	else  std::cout << "* Error: The DESCRIPTION has not been copied *" << std::endl;

//Allocation PRICE
	this->c_price = price;

//Allocation IsDaily
	if(daily == 'y' || daily == 'Y')
		this->c_IsDaily = true;
	else if (daily == 'n' || daily == 'N')
		this->c_IsDaily = false;
	else  std::cout << "* Error: IsDAILY has not been copied *" << std::endl;
}
*/
void sdds::FoodOrder::setEmpty()
{
	char c_order { 0 };
	char c_name[lenName + 1] { '\0' };
	char c_descrip[lenDesc + 1] { '\0' };
	bool c_IsDaily{ false };
	double c_price{ };
}

void sdds::FoodOrder::read(std::istream& istr)
{
	setEmpty();

	char custName[10];
	istr.get(custName, 10, ',');

	istr.ignore();

	string foodDesc;
	getline(istr, foodDesc, ',');

	double foodPrice = -1;
	istr >> foodPrice;

	istr.ignore();

	char dailySpecialStatus;
	istr >> dailySpecialStatus;

	if (!istr.fail()) {
		// all data were read successfully, use the set private function to set values of the object to read value
		this->setFoodOrder(custName, foodDesc.c_str(), foodPrice, dailySpecialStatus);
	}
}

void sdds::FoodOrder::setFoodOrder(char* name, string descrip, double price, char daily)
{

	//Length Name
	int len = strlen(name);
	//Allocation Name
	if (len != '\0' && len > 2)
		strncpy(this->c_name, name, lenName);
	//c_string() CONVERT STRING into CONST CHAR*
	else  std::cout << "* Error: The NAME has not been copied *" << std::endl;

	//Length Description
	//len = strlen(descrip);
	len = descrip.length();
	//Allocation Description 
	if (len != '\0' && len > 0)
		strncpy(this->c_descrip, descrip.c_str(), lenDesc);
	else  std::cout << "* Error: The DESCRIPTION has not been copied *" << std::endl;

	//Allocation PRICE
	this->c_price = price;

	//Allocation IsDaily
	if (daily == 'y' || daily == 'Y')
		this->c_IsDaily = true;
	else if (daily == 'n' || daily == 'N')
		this->c_IsDaily = false;
	else  std::cout << "* Error: IsDAILY has not been copied *" << std::endl;
}