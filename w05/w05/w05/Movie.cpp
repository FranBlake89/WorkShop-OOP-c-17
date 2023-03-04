
/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/


#include <algorithm>
#include <iomanip>
#include <string>
#include "Movie.h"

namespace sdds {
	const std::string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const std::string& strMovie) {
		std::string s = strMovie;
		m_title = trim(s);
		m_release = std::stoi(trim(s));
		m_description = s.substr(s.find_first_not_of(" \f\n\r\t\v"), s.find_last_not_of(" \f\n\r\t\v") + 1);;
	}

	std::ostream& operator<<(std::ostream& ostr, const Movie& obj) {
		if (!obj.title().empty()) {
			ostr << std::setw(40) << obj.title() << " | ";
			ostr << std::setw(4) << obj.m_release << " | ";
			ostr << obj.m_description << std::endl;
		}
		return ostr;
	}
	// new way the remove space, reference from "boost" library
	std::string Movie::trim(std::string& str) {
		const char* spaces = " \f\n\r\t\v";
		std::string s;
		s = str.substr(0, str.find(","));
		s.erase(0, s.find_first_not_of(spaces));
		s.erase(s.find_last_not_of(spaces) + 1);
		str.erase(0, str.find(",") + 1);
		return s;
	}
}
