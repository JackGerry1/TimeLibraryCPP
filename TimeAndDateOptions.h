#pragma once

#include <string>

class TimeAndDateOptions
{
public:

	TimeAndDateOptions(); 

	std::string GetTime();
	std::string GetDateTime();
	std::string GetDate();
	std::string DifferenceBetweenTimes();
	int calculateWaitingTime();

};

