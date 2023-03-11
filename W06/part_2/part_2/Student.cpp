
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
#include "Utilities.h"

using namespace std;

namespace sdds {
	Student::~Student()
	{
		//here destructor loop
	}
	Student::Student(istream& in)
	{
		if (in) {
			//PROBLEM WITH STUDENT CHECK AGE THROW ERROR 
			//sophia aiden doesn't print out
			//s, Sophia Aiden,se79, S902890
			string temp, tag, name, age, id, num_courses, list_courses;
			int count_courses{};

			getline(in, tag, ',');
			getline(in, name, ',');

			getline(in, temp, ',');
			age = trim(temp);

			getline(in, id, ',');
			//id = trim(temp);

			getline(in, num_courses, ',');
			//num_courses = trim(temp);
			try {
				if (!isNumber(age)) {
					throw string(num_courses + "++Invalid record!(num c)");
				}
				else {
					count_courses = stoi(num_courses);
				}
			}
			catch (const string& e) {
				cout << e << endl;
			}

			while (count_courses != 2) {
				getline(in, list_courses, ',');
				m_courses.push_back(list_courses);
				count_courses--;
			}
			getline(in, list_courses);
			m_courses.push_back(list_courses);

			m_name = name;
			m_id = id;
			m_age = stoi(age);
			m_num_courses = stoi(num_courses);
			
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
	
		for (auto& student : m_courses) {
			out << " " << student;
		}
		out << "\n";// << m_name << " " << m_id << " " << m_courses << endl;
	}

}
