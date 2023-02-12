#pragma once

#include <iostream>


namespace sdds {

class Toy
{
	unsigned int t_order_id {};
	std::string t_name ;
	unsigned int t_num_toys {};
	double t_price {};
	double t_tax {};

public:
	void update(int numItems);
	Toy(const std::string& toy);
	friend std::ostream& operator<<(std::ostream& os, const Toy& obj);
};

}

