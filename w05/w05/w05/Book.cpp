/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <functional>
#include <iomanip>

#include "Book.h"
using namespace std;
namespace sdds {
	void Book::setObject(const string& author, const string& title, const string& country, const string& descrip, const size_t& year, const double& price)
	{
		m_author = author;
		m_title = title;
		m_country = country;
		m_description = descrip;
		m_year = year;
		m_price = price;
	}
	void Book::setPrice(double& price)
	{
		m_price = price;
	}
	const string& sdds::Book::title() const
	{
		return m_title;
	}
	const string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{	//	a function that returns the price by reference, 
		//	allowing the client code to update the price
		return m_price;
	}
	Book::Book(const string& strBook)
	{
		// Extract info and set it in Object
		//AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION

		string line{}, author{}, title{}, country{}, descrip{};
		size_t year{};
		double price{};
		
		line = strBook;
		//author
		size_t positionSeparator = line.find(",");
		author = line.substr(0, positionSeparator);
		line.erase(0, positionSeparator + 1);
		//title
		positionSeparator = line.find(",");
		title = line.substr(0, positionSeparator);
		line.erase(0, positionSeparator + 1);
		//country
		positionSeparator = line.find(",");
		country = line.substr(0, positionSeparator);
		line.erase(0, positionSeparator + 1);
		//price
		positionSeparator = line.find(",");
		price = stod(line.substr(0, positionSeparator));
		line.erase(0, positionSeparator + 1);
		//year
		positionSeparator = line.find(",");
		year = stod(line.substr(0, positionSeparator));
		line.erase(0, positionSeparator + 1);
		//description
		positionSeparator = line.find(".");
		descrip = line.substr(0, positionSeparator+1);
		line.erase(0, positionSeparator + 1);

		//Removing space Around
		author = removeSpace(author);
		title = removeSpace(title);
		country = removeSpace(country);
		descrip = removeSpace(descrip);

		//Setting values
		if (author != "" && title != "" && country != "" && descrip != "")
			setObject(author, title, country, descrip, year, price);
		else
			cout << "ERROR CONSTRUCTOR ........." << endl;
	}
	std::string Book::removeSpace(const string& str)
	{
		string strNew{};
		strNew = str;

		// Removing blank spaces from 
		size_t first_No_blank{}, last_No_blank{};
		size_t length{};

		// strNew    ----------------------   
		first_No_blank = strNew.find_first_not_of(' ');
		last_No_blank = strNew.find_last_not_of(' ');
		length = strNew.length();

		//stack overflow --> BACK() , Prof. --> FRONT()
		if (strNew.front() == ' ') {
			strNew.erase(0, first_No_blank);

			last_No_blank = strNew.find_last_not_of(' ');
		}

		if (strNew.back() == ' ')
			strNew.erase((last_No_blank + 1), (length));
		
		return strNew;
	}

	std::ostream& Book::write(std::ostream& os) const
	{

		os << std::setw(20) << std::right << m_author;
		os << " | ";
		os << std::setw(22) << std::right << m_title;
		os << " | ";
		os << std::setw(5) << std::right << m_country;
		os << " | ";
		os << std::setw(4) << m_year;
		os << " | ";
		os << std::setw(6) << std::right << std::fixed << std::setprecision(2) << m_price;
		os << " | ";
		os << m_description << std::endl;

		return os;
	}

	void Book::set(double& price, const char& member)
	{
		if(member == 'p')
			setPrice(price);
	}

	ostream& operator<<(ostream& os, const Book& obj)
	{
		obj.write(os);
		return os;
	}

}

