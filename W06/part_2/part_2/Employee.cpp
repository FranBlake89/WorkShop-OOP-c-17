
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

using namespace std;

namespace sdds {

	Employee::Employee(istream& is)
	{
		string tag{};
		char comma{};
		getline(is, tag, ',');
		getline(is, m_name, ',');
		
		//cout << "name " <<m_name <<endl;
		if (m_name.empty())
			throw invalid_argument("Error in name");

		is >> m_age >> comma;
		//cout << "age " << m_age << " comma " << comma << endl;
		if (!is || comma != ',')
			throw invalid_argument(m_name + "++Invalid record! (1)");

		getline(is, m_id);
		//cout << "id " << m_id << " comma " << comma << endl;
		if (m_id.empty() )
			throw invalid_argument(m_name + "++Invalid record! (2)");
		
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
		out << status();
		out << "|";
		out << setw(10);
		out << left;
		out << id();
		out << " |";
		out << setw(20);
		out << left;
		out << name();
		out << "  | ";
		out << setw(3);
		out << age();
		out << " |";
		
	}



}
