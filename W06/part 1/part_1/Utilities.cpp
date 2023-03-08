
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

#include "Utilities.h"
#include "Employee.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

namespace sdds {

    Person* buildInstance(std::istream& input)
    {
        char tag = input.peek();
        Employee* emp = nullptr;
        if (tag == 'e' || tag == 'E') {
            string line{};

            //get initial position
            streampos init_pos = input.tellg();

            if (!errorInLine(input)) {
                input.seekg(init_pos);
                emp = new Employee(input);
               
               return emp;
            }
            else {
                return nullptr;
            }
        }
        else {
            string line;
            getline(input, line);
            return nullptr;
        }
        
    }
    bool errorInLine(std::istream& is)
    {
        bool errors = false;

        string tag, name, is_num, id, temp;

        getline(is, tag, ','); // get the tag, which is ignored
        getline(is, temp, ',');
        name = trim(temp);

        getline(is, is_num, ',');

        if (!isNumber(is_num)) {
            errors = true;
        }

        getline(is, temp);
        id = trim(temp);
        try {
            if (toupper(id[0]) != toupper(tag[0])) {
                errors = true;
                throw string(name + "++Invalid record!");
            }
        }
        catch (const string& e) {
            cout << e << endl;
        }

        return errors;
    }
    bool isNumber(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    string trim(const string& str) {
        int first_No_blank{}, last_No_blank{};
        size_t length{};
        string temp{};

        if(!str.empty())
            temp = str;
      
        first_No_blank = temp.find_first_not_of(' ');
        last_No_blank = temp.find_last_not_of(' ');
        length = temp.length();
        
        if (temp.front() == ' ')
            temp.erase(0, first_No_blank);
        
        if (temp.back() == ' ')
            temp.erase((last_No_blank), (length));
        
        return temp;

    }
}

/* REMOVE SPACE
       * NOTE: doesn't work properly in Linux (Apparently)

       string response{};

        string::size_type start = str.find_first_not_of(" \t");
        string::size_type end = str.find_last_not_of(" \t");
        if (start == string::npos || end == string::npos) {
            response = "";
        }

        response = str.substr(start, end - start + 1);
        return response;
 */