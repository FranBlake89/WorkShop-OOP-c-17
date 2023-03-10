#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "College.h"
#include "Person.h"

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
            m_persons[i]->display(out);
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
                << "|"
                << setw(10)
                << left
                << person->id()
                << " |"
                << setw(20)
                << left
                << person->name()
                << "  | "
                << setw(3)
                << person->age()
                << " |" << endl;
   
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;


    }
  
}

