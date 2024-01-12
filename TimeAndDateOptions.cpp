#include "TimeAndDateOptions.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <windows.h>

// constructor for TimeAndDateOptions
TimeAndDateOptions::TimeAndDateOptions() {}

// Function: GetTime
// Objective: format time into HH-MM-SS
std::string TimeAndDateOptions::GetTime() {
	// Get current unformatted time
	time_t now = time(0);

	// Create a 'tm' structure to store the broken-down time
	tm ltm;

	// Convert 'time_t' to a local time and store it in 'ltm'
	localtime_s(&ltm, &now);

	// Create a string stream to format the time, before formatting the time as "hh:mm:ss"
	std::ostringstream formattedTime;
	formattedTime << std::put_time(&ltm, "%T");

	// return the time
	return formattedTime.str();
} // end of GetTime

// Function: GetDateTime
// Objective: format the date and time into YYYY-MM-DD HH-MM-SS
std::string TimeAndDateOptions::GetDateTime()
{
	// Get current unformatted time as 'time_t'
	time_t now = time(0);

	// Create a 'tm' structure to store the broken-down time
	tm ltm;

	// Convert 'time_t' to a local time and store it in 'ltm'
	localtime_s(&ltm, &now);

	// Create a string stream to format the date and time as: DD-MM-YYYY HH:MM:SS
	std::ostringstream oss;

	// you can rearrange the date and time in any order for example YYYY-MM-DD HH:MM:SS, 
	// would be -> "oss << std::put_time(&ltm, "%Y-%m-%d %H:%M:%S")"
	oss << std::put_time(&ltm, "%Y-%m-%d %H:%M:%S");

	// convert string stream to string
	std::string dateTime = oss.str();

	// Return the formatted date and time
	return dateTime;
} // end of GetDateTime

// Function: GetDate
// Objective: format the date and time into DD-MM-YYYY
std::string TimeAndDateOptions::GetDate()
{
	// Get current unformatted time
	time_t now = time(0);

	// Create a 'tm' structure to store the broken-down date
	tm ltm;

	// Convert 'time_t' to a local date and store it in 'ltm'
	localtime_s(&ltm, &now);

	// Create a string stream to format the date
	std::ostringstream oss;

	// you can rearrange the date and time in any order for example DD-MM-YY, 
	// would be -> "oss << std::put_time(&ltm, "%d-%m-%Y")"
	oss << std::put_time(&ltm, "%Y-%m-%d"); // Format: YYYY-MM-DD

	// Convert the formatted date from the string stream to a string and return it
	return oss.str();
} // end of GetDate

// Function: DifferenceBetweenTimes
// Objective: take the waiting time and convert into format 0h, 0m, 0s.
std::string TimeAndDateOptions::DifferenceBetweenTimes()
{
	// get the waiting time from the other function
	int waitingTime = calculateWaitingTime();

	// split into hours, minutes and seconds
	int hours = waitingTime / 3600;
	int minutes = (waitingTime % 3600) / 60;
	int seconds = waitingTime % 60;

	// format into 0h, 0m, 0s
	std::string formattedWaitingTime = std::to_string(hours) + "h, " + std::to_string(minutes) + "m, " + std::to_string(seconds) + "s";

	// outupt the formated waiting time
	return formattedWaitingTime;
} // end of DifferenceBetweenTimes

// Function: calculateWaitingTime
// Objective: to calculate the waiting time based on the difference between it and the afterDelay time 
int TimeAndDateOptions::calculateWaitingTime() {
	// Get current time
	time_t now = time(0);

	// this is a simple five second delay, 
	// you can replace this with any additional functionality of your program
	// for example keeping track of how long a user has been in a queue. 

	// or you could have a different function, which will get the time that is was called
	// then pass it into this function before it gets it current time in this function
	Sleep(5000);

	// get time after 5 second delay
	time_t afterDelay = time(0);
	
	// Calculate waiting time
	return afterDelay - now;

} // end of calculateWaitingTime