
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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Person.h"

using namespace std;
namespace sdds {
    
    Person* buildInstance(std::istream& input);
    bool errorInLine(std::istream& input);

    bool isNumber(const string& str);
    string trim(const string& str);

} 

#endif // !SDDS_UTILITIES_H