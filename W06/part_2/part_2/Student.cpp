
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

#include "Student.h"

using namespace std;

namespace sdds {
	Student::~Student()
	{
		//here destructor loop
	}
	Student::Student(istream& in)
	{
		if (in) {
			string tag, name, age, id, num_courses, list_courses;

			in >> tag >> name >> age >> id >> num_courses >> list_courses;

			cout << "STUDENT   " 
				<< tag << " " << name << age << id << "  " << num_courses << "  " << list_courses << endl;
				

			//getline(in, tag, ',')  // ?? this
		}
	}

	string Student::status() const
	{
		return "Student";
	}

	string Student::name() const
	{
		return m_name;
	}

	string Student::id() const
	{
		return m_id;
	}

	string Student::age() const
	{
		return to_string(m_age);
	}

	void Student::display(ostream& out) const
	{
		out << "display func  " << endl;// << m_name << " " << m_id << " " << m_courses << endl;
	}

}

