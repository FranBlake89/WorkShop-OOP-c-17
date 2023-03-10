
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
#include <string>
#include<vector>

#include "Person.h"

using namespace std;

namespace sdds {
	class Student : public Person {
	private:
		string m_name{};
		string m_id{};
		vector<string> m_courses;
		unsigned int m_age{};
		int m_num_courses{};

	public:
		Student() = default;
		~Student();
		Student(istream& in);
		string status() const override;
		string name() const override;
		string id() const override;
		string age() const override;
		void display(ostream& out) const override;

		//disable copy operations
		Student(Student&) = delete;
		Student& operator=(const Student&) = delete;


	};

}