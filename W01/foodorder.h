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
	static int counter = 1;

	class FoodOrder {
		char c_order = { 0 };
		char c_name[lenName + 1] = { '\0' };
		char c_descrip [lenDesc +1] = { '\0' };
		double c_price = 0;
		bool c_IsDaily = false;

	private:
		//void setFoodOrder(string name, string descrip, double price, char daily);
		void setFoodOrder(char* name, string descrip, double price, char daily);
		void setEmpty();
	public:
		void  read(std::istream& in);
		void display();

	};

}


#endif