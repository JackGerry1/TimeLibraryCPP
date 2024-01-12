#include "FormattedTime.h"
#include <iostream>
#include <sstream>
#include <iomanip>

void FormattedTime::FormatTime() {
	// Get current unformatted time
	time_t now = time(0);

	// Create a 'tm' structure to store the broken-down time
	tm ltm;

	// Convert 'time_t' to a local time and store it in 'ltm'
	localtime_s(&ltm, &now);

	// Create a string stream to format the time, before formatting the time as "hh:mm:ss"
	std::ostringstream formattedTime;
	formattedTime << std::put_time(&ltm, "%T");

	std::cout << formattedTime.str() << std::endl;
}