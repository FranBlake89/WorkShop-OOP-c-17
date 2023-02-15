/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/
#define  _CRT_SECURE_NO_WARNINGS
#include "Toy.h"
#include "ConfirmOrder.h"

using namespace std;

namespace sdds {

	ConfirmOrder::ConfirmOrder() { ; }

	ConfirmOrder::~ConfirmOrder()
	{
		delete[] m_toy;
	}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& c)
	{
		operator=(c);
	}


	ConfirmOrder::ConfirmOrder(ConfirmOrder&& c)
	{
		operator =(move(c));
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& c)
	{
		// TODO: insert return statement here
		if (this != &c) {
			m_length = c.m_length;

			delete[] m_toy;
			m_toy = new const Toy * [m_length] {};

			for (size_t i = 0; i < m_length; i++)
			{
				m_toy[i] = c.m_toy[i];
			}			
		}

		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& c)
	{
		// TODO: insert return statement here
		if (this != &c) {
			m_length = c.m_length;
			m_toy = c.m_toy;

			c.m_toy = nullptr;
			c.m_length = 0;
		}

		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool is_uniq = true;

		for (size_t i = 0; i < m_length; i++)
		{
			if ( m_toy[i] == &toy ) {
				is_uniq = false;
			}
		}

		if (is_uniq) {
			const Toy** toys = new const Toy * [m_length + 1] {};

			for (size_t i = 0; i < m_length; i++)
			{
				toys[i] = m_toy[i];
			}

			delete[] m_toy;
			m_toy = toys;

			m_toy[m_length++] = &toy;

		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool found = false;
		int index;

		for (size_t i = 0; i < m_length && !found; i++) {
			if (m_toy[i] == &toy) {
				index = i;
				found = true;
			}
		}
		if (found) {
			m_toy[index] = nullptr;
		}
		return *this;
	}

	ConfirmOrder::operator bool() const {
		return m_toy;
	}

	std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& c)
	{
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;

		if (c.m_toy != nullptr) {
			for (size_t i = 0; i < c.m_length; i++)
			{
				if (c.m_toy[i]) {
					ostr << *(c.m_toy[i]);
				}
			}
		}
		else {
			ostr << "There are no confirmations to send!" << std::endl;
		}
		ostr << "--------------------------" << std::endl;

		return ostr;
	}

}

