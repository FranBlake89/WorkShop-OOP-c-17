/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/
#pragma once

#include <iostream>

namespace sdds {

	class Toy
	{
		unsigned int t_order_id {};
		unsigned int t_num_toys {0};
		std::string t_name{};
		double t_price {0};
		double t_tax {0};

	public:
		Toy();
		void update(int numItems);	
		Toy(const std::string& toy);
		std::ostream& write(std::ostream& ostr)const;

	};
//friend function helper
	std::ostream& operator<<(std::ostream& os, const Toy& obj);

}

