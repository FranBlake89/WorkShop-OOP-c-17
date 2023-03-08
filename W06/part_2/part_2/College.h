
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

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"

using namespace std;

namespace sdds {

	class College {
	private:
		vector<Person*> m_persons;
	public:
		College() = default;
		//disable copy operators
		College(const College&) = delete;
		College& operator=(const College&) = delete;

		//add Person to college
		College& operator+=(Person* thePerson);
		void display(ostream& out) const;

		~College();


	};

}