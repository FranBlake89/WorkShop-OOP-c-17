
/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
const int noOfWords = 6;
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[noOfWords]{};
		std::string m_goodWords[noOfWords]{};
		int m_numReplaced[noOfWords]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif //!SDDS_SPELLCHECKER_H