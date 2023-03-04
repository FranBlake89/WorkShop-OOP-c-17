
/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include<iostream>
#include<string>
namespace sdds {
	class Movie {
		std::string m_title{};
		int m_release{};
		std::string m_description{};
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& obj);
		std::string trim(std::string& str);
	};
}

#endif //!SDDS_MOVIE_H