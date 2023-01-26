#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

namespace sdds {
	const int MAX_SIZE = 10;
	class TimedTask
	{
		int m_records;
		std::chrono::steady_clock::time_point m_start_point;
		std::chrono::steady_clock::time_point m_end_point;

		struct Task {
			string t_name;
			string t_unit_time;
			std::chrono::steady_clock::duration s_duration;
		} arr[MAX_SIZE];
	public:
		TimedTask() = default;
		void startClock();
		void stopClock();
		void addTask(const char* name);
		friend std::ostream& operator<<(std::ostream& left, const TimedTask& obj);
	};

}

