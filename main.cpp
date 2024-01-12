// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TimeAndDateOptions.h"
int main()
{
	TimeAndDateOptions t;

	std::cout << "The Current Time Is: " << t.GetTime() << std::endl;
	std::cout << "The Current Date And Time Is: " << t.GetDateTime() << std::endl;
	std::cout << "The Current Date Is: " << t.GetDate() << std::endl;
	std::cout << "Waiting Time After 5 Seconds Is: " << t.DifferenceBetweenTimes();
}

