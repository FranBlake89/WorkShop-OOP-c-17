/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <functional>
#include <iomanip>

#include "Toy.h"

using namespace std;
namespace sdds {

    Toy::Toy() { /**/ }

    void Toy::update(int numItems)
    {
        t_num_toys = numItems;
    }
    Toy::Toy(const string& toy)
    {
        string temp{};
        temp = toy;

        int first = temp.find(":");
        int id = std::stoi(temp.substr(0, first)); //change by STOLL, because stoll work with unsigned long long. 
        temp.erase(0, first + 1);

        int second = temp.find(":");
        string name = temp.substr(0, second);
        temp.erase(0, second + 1);

        int third = temp.find(":");
        int num = std::stoi(temp.substr(0, third));
        temp.erase(0, third + 1);

        double price = std::stod(temp);


        // Removing blank spaces from 
        int first_No_blank{}, last_No_blank{};
        size_t length{};
        // NAME    ----------------------   
        first_No_blank = name.find_first_not_of(' ');
        last_No_blank = name.find_last_not_of(' ');
        length = name.length();

        //stack overflow --> BACK() , Prof. --> FRONT()
        if (name.front() == ' ')
            name.erase(0, first_No_blank);

        if (name.back() == ' ')
            name.erase((last_No_blank + 1), (length));
        // -----------------------------     

        t_order_id = id;
        t_name = name;
        t_num_toys = num;
        t_price = price;
        t_tax = 0.13;
    }

    ostream& Toy::write(ostream& os) const
    {
        double dec_subTotal{};
        dec_subTotal = (double)(t_price * t_num_toys);

        os << "Toy " << t_order_id << ":";
        os << std::setw(18) << std::right << t_name;
        os << std::setw(3) << std::right << t_num_toys << " items";
        os << std::setw(8) << std::right << t_price << "/item  ";
        os << "subtotal:" << std::setw(7) << std::right << std::fixed << std::setprecision(2) << dec_subTotal;
        os << " tax:" << std::setw(6) << std::right << std::setprecision(2) << (dec_subTotal * t_tax);
        os << " total:" << std::setw(7) << std::right << std::setprecision(2) << (dec_subTotal + (dec_subTotal * t_tax)) << std::endl;

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Toy& obj)
    {
       obj.write(os);
       return os;
    }

}

/*
void sdds::Toy::update(int numItems)
{
	this->t_num_toys = numItems;
}

sdds::Toy::Toy(const std::string& toy)
{
	std::string temp{};
	temp = toy; 

	int first = temp.find(":");
    int id = std::stoi(temp.substr(0, first)); //change by STOLL, because stoll work with unsigned long long. 
    temp.erase(0, first + 1);

    int second = temp.find(":");
    std::string name = temp.substr(0, second);
    temp.erase(0, second + 1);

    int third = temp.find(":");
    int num = std::stoi(temp.substr(0, third));
    temp.erase(0, third + 1);

    double price = std::stod(temp);


    // Removing blank spaces from 
    int first_No_blank{}, last_No_blank{};
    size_t length{};
    // NAME    ----------------------   
    first_No_blank = name.find_first_not_of(' ');
    last_No_blank = name.find_last_not_of(' ');
    length = name.length();

    //stack overflow --> BACK() , Prof. --> FRONT()
    if (name.front() == ' ')
        name.erase(0, first_No_blank);
    
    if (name.back() == ' ')
        name.erase( (last_No_blank +1), (length) );
    // -----------------------------     

    t_order_id = id;
    t_name = name;
    t_num_toys = num;
    t_price = price;
    t_tax = 0.13;

}

void sdds::Toy::display() const
{
   std::cout << *this ;
}

std::ostream& sdds::operator<<(std::ostream& os, const Toy& obj)
{
    //float two_dec_subTotal{}, two_dec_tax{}, two_dec_total{};

    double dec_subTotal{};
    dec_subTotal = (double) (obj.t_price * obj.t_num_toys);

    os << "Toy " << obj.t_order_id << ":";
    os << std::setw(18) << std::right << obj.t_name; 
    os << std::setw(3) << std::right << obj.t_num_toys << " items";
    os << std::setw(8) << std::right << obj.t_price << "/item  "; 
    os << "subtotal:" << std::setw(7) << std::right << std::fixed << std::setprecision(2) << dec_subTotal;
    os << " tax:" << std::setw(6) << std::right << std::setprecision(2) << (dec_subTotal * obj.t_tax);
    os << " total:" << std::setw(7) << std::right << std::setprecision(2) << ( dec_subTotal + (dec_subTotal * obj.t_tax) ) << std::endl;

    return os;
}
*/