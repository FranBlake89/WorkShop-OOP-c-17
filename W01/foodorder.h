/* 
   ---------------------------------------
Name:		Francisco Castillo
Seneca Id:	148904212
e-mail:		fcastillo-rojas1@myseneca.ca
Section:	NDD
   ---------------------------------------
*/
#ifndef SSDS_FOODORDER_H
#define SSDS_FOODORDER_H

using namespace std;

const size_t lenName = 9, lenDesc = 24;
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {

	class FoodOrder {
		char c_order;
		string c_name;
		string c_descrip;
		double c_price;
		bool c_IsDaily;

	private:
		void setFoodOrder( string name,  string descrip, double price, char daily);
		void setEmpty();
	public:
		FoodOrder();
		void  read(std::istream& in);
		void display();
		bool isEmpty();

	};

}


#endif