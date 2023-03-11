
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
#include <sstream>


#include "Professor.h"
#include "Employee.h"
#include "Utilities.h"

using namespace std;

namespace sdds {


	Professor::Professor(std::istream& in)
	{
		if (in) {
			string tag{}, temp{};
			string name{}, id{}, age{}, department{};
			char t{};

			//in >> tag;
			getline(in, temp, ',');
			tag = trim(temp);
			t = tag[0];
			getline(in, name, ',');
			getline(in, age, ',');
			getline(in, id, ',');
			
			
			try {
				if (t != 'p' && t != 'P')
					throw string("Invalid tag expected 'p' or 'P'.");
				else {
					getline(in, department);
					//cout << tag << name << age << id << department;
					m_department = department;
					setName(name);
					setID(id);

					size_t newAge;
					stringstream sstream(age);
					sstream >> newAge;
					setAge(newAge);
				}
			}
			catch (const string& e) {
				cout << e << endl;
			}
			


		}
	}

	void Professor::display(ostream& out)
	{

		out << "***| ";
		out << setw(10);
		out << left;
		out << Employee::status();
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
		out << " |" << m_department << "|" << '"' << status() << '"' << endl;


	}

	string Professor::status() const
	{
		return "Professor";
	}

	string Professor::department() const
	{
		return m_department;
	}

}
