
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

#include "Employee.h"
#include "Utilities.h"
#include "Professor.h"

using namespace std;

namespace sdds {

	Employee::Employee(istream& is)
	{
		string tag{}, name{}, id{}, temp{};
		char comma{};
		getline(is, tag, ',');
		getline(is, name, ',');
		is >> m_age >> comma;
		getline(is, id);
		
		m_name = trim(name);
		m_id = trim(id);
		
	}

	string Employee::status() const
	{
		return "Employee";
	}

	string Employee::name() const
	{
		return m_name;
	}

	string Employee::id() const
	{
		return this->m_id;
	}

	string Employee::age() const
	{
		return to_string(m_age);
	}

	void Employee::display(ostream& out) const
	{
		out << "| ";
		out << setw(10);
		out << left;
		out << Employee::status();
		out << "| ";
		out << setw(10);
		out << left;
		out << id();
		out << "| ";
		out << setw(20);
		out << left;
		out << name();
		out << " | ";
		out << setw(3);
		out << age();
		out << " |";
		
	}

	void Employee::setName(string name)
	{
		m_name = name;
	}

	void Employee::setID(string ID)
	{
		m_id = ID;
	}

	void Employee::setAge(size_t age)
	{
		m_age = age;
	}



}
