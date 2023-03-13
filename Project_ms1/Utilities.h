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

#ifndef PROJECT_MS1_UTILITIES_H
#define PROJECT_MS1_UTILITIES_H
#include <iostream>
#include <string>

using namespace std;

namespace sdds {


    class Utilities {
        size_t m_widthField { 1 };
        char m_delimiter{}; // or string type ??
    public:
        void setFIeldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        string extractToken(const string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };

} // sdds

#endif //PROJECT_MS1_UTILITIES_H
