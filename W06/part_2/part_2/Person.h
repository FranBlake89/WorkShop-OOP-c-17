
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

#ifndef SDDS_PERSON_H
#define SDDS_PERSON_H
#include <iostream>
#include <string>

namespace sdds
{
	class Person
	{
	public:
		virtual std::string status() const = 0;
		virtual std::string name() const = 0;
		virtual std::string age() const = 0;
		virtual std::string id() const = 0;
		virtual void display(std::ostream&) const = 0;
		
		virtual ~Person() = default;
	};
}

#endif