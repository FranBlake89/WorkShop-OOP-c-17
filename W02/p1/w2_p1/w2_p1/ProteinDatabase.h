#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

namespace sdds {

	class ProteinDatabase
	{
		string arr[]{nullptr};
	public:
		ProteinDatabase() = default;
		ProteinDatabase( string fileName );
		size_t size();
		std::string operator[]( size_t index );

	};

}

