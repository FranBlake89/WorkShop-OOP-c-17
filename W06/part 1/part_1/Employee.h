
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

#include "Person.h"

using namespace std;

namespace sdds {

	class Employee : public Person {
	private:
		string m_name{};
		string m_id{};
		size_t m_age{};
	public:
		Employee() = default;
		Employee(istream& in); // constructor code that uses the istream object
		
		string status() const override; //a query that returns the string Employee
		string name() const override;
		string id() const override;
		string age() const override;
		void display(ostream& out)const override; // query inserts in the first parameter the content of the employee object in the format | "EMPLOYEE" | id | name | age |


	};
}