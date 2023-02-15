/*
Name: Francisco Castillo
Section: NDD
Seneca ID: 148904212
*/
#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace sdds {
	class Book
	{
		string m_author{};
		string m_title{};
		string m_country{};
		string m_description{};
		size_t m_year{};
		double m_price{};
	private:
		void setObject(const string& author, const string& title, const string& country, const string& descrip, const size_t& year, const double& price);
		void setPrice(double& price);
	public:
		Book() = default;
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const string& strBook);
		string removeSpace(const string& str);
		std::ostream& write(std::ostream& ostr)const;
		void set(double& price, const char& member);
	};

	//friend function helper
	ostream& operator <<(ostream& os, const Book& obj);
}



