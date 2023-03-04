
/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file)
			throw "Bad file name!";
		else {
			std::string s{ "" };
			size_t i = 0u;
			do {
				std::getline(file, s);

				if (file) {
					size_t space = s.find(' ');
					m_badWords[i] = s.substr(0, space);
					s.erase(0, space);
					s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
					m_goodWords[i] = s;
					i++;
				}
			} while (file);
		}
	}
	void SpellChecker::operator()(std::string& text){
		size_t found = 0;
		for (size_t i = 0; i < noOfWords; i++) {
			while ((found = text.find(m_badWords[i])) != std::string::npos) {
				text.replace(found, m_badWords[i].length(), m_goodWords[i]);
				m_numReplaced[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < noOfWords; i++){
			out << std::right << std::setw(15) << m_badWords[i] << ": " << m_numReplaced[i] << " replacements" << std::endl;
		}
	}
}