/*
Name: Francisco Castillo
Section: NDD
Seneca ID: 148904212
*/
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <string>
#include <iostream>
using namespace std;
namespace sdds
{
	class Book
	{
	
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_description{};
	private:
		void setObject(const string& author, const string& title, const string& country, const string& descrip, const size_t& year, const double& price);
		void setPrice(double& price);
	public:
		Book() = default;
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		std::string removeSpace(const std::string& str);
		std::ostream& write(std::ostream& ostr)const;
		void set(double& price, const char& member);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		};

	};
	ostream& operator <<(ostream& os, const Book& obj);
}
#endif


