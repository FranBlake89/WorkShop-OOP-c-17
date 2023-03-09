
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

#include"Employee.h"

using namespace std;

namespace sdds {
	class Professor: public Employee
	{
	private:
		string m_department{};
	public:
		Professor() = default;
		Professor(std::istream& in);
		void display(ostream& out);
		string status() const;
		string department() const;



	};

}

