
/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/

#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace sdds {

	class SpellChecker
	{
		string m_badWords[6];
		string m_goodWords[6];

	public:
		SpellChecker(const char* filename);
		void operator()(string& text);
		void showStatistics(ostream& out) const;
	};
}

