/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "SpellChecker.h"

using namespace std;
namespace sdds {

	SpellChecker::SpellChecker(const char* filename)
	{
		if (filename) {
			string line{}, badWord{}, goodWord{};
			
			ifstream fileStream(filename);

			fileStream.open(filename);

			if (fileStream.is_open()) {
				int count = 0;
				while (getline(fileStream, line) )
				{
					fileStream >> badWord;
					fileStream >> goodWord;

					cout << badWord << "   " << goodWord << endl;
					
					m_badWords[count] = badWord;
					m_goodWords[count] = goodWord;

					count++;
				}


			}

		}
		else {
			//exception of type const char*
			//message Bad file name!
			const char* msg;
			msg = "Bad file name!";
			
			throw out_of_range(msg);
			
		}


	}
	void SpellChecker::operator()(string& text)
	{
		int count = 0;
		size_t length = m_badWords->length();

		for (size_t i = 0; i < length; i++)
		{
			if (text == m_badWords[i]) {
				m_badWords[i] = text;
				count++;
			}
		}

	}
}
