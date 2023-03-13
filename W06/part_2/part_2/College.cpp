
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
#include <vector>
#include <iomanip>

#include "College.h"
#include "Person.h"
#include "Professor.h"

using namespace std;

namespace sdds {
    College::~College()
    {
        for (auto& person : m_persons)
            delete person;
    }
    College& sdds::College::operator+=(Person* thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }

    void sdds::College::display(ostream& out) const
    {

        int count = 1;

        if (count == 1) {
            out << "------------------------------------------------------------------------------------------------------------------------\n"
                "|                                        Test #1 Persons in the college!                                               |\n"
                "------------------------------------------------------------------------------------------------------------------------\n";
            count++;
        }
       
        for (size_t i = 0; i < m_persons.size(); ++i) {
         
               //This is usefull when the professor display function is not const, so it is not overrride
                // Professor professor = dynamic_cast<Professor&>(*m_persons[i]);
               // professor.display(out);
               
            m_persons[i]->display(out);
            out << endl;
        }
        
        
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #2 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (const auto& person : m_persons)
        {
            out << "| "
                << setw(10)
                << left
                << person->status()
                << "| "
                << setw(10)
                << left
                << person->id()
                << "| "
                << setw(20)
                << left
                << person->name()
                << " | "
                << setw(3)
                << person->age()
                << " |" << endl;
   
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;


    }
  
}

