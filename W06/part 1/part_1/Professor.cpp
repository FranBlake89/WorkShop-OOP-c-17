
/*
> Name: Francisco Castillo
> Course: OOP
> Section: NDD
> Seneca ID: 148904212
> Seneca email: fcastillo-rojas1@myseneca.ca
> Date of completion: 2023-mm-dd

* I confirm that I am the only author of this file
 and the content was created entirely by me.
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "Professor.h"

using namespace std;

namespace sdds {
Professor::Professor(std::istream& in) : Employee(in), m_department("")
{
	if (in) {
		char tag{};
		string name{}, id{}, age{}, department{};

		
		in >> tag >> name >> age >> id >> department;

		if (tag != 'p' || tag != 'P')
			throw "Invalid tag expected 'p' or 'P'.";

		m_department = department;

	}
}

}
