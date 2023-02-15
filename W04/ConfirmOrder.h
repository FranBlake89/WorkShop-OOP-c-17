/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/


#pragma once
#include <string>
#include <iostream>
#include "Toy.h"

namespace sdds {
	class ConfirmOrder
	{
		const Toy** m_toy{ nullptr };
		size_t m_length{};

	public:
		ConfirmOrder();

		//rule of five
		ConfirmOrder(const ConfirmOrder& c);
		ConfirmOrder(ConfirmOrder&& c) ;
		ConfirmOrder& operator = (const ConfirmOrder& c);
		ConfirmOrder& operator = (ConfirmOrder&& c) ;
		virtual ~ConfirmOrder();
		
		
		ConfirmOrder& operator +=(const Toy& toy);
		ConfirmOrder& operator -=(const Toy& toy);
		friend std::ostream& operator << (std::ostream& ostr, const ConfirmOrder& c);
		operator bool() const;

	};


}

