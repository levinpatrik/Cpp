#include "Date.h"
#include <iostream>

void current_time()
{
	time_t mytime;
	struct tm *t = gmtime(&mytime);
	int year = t->tm_year + 1900;
	int month = t->tm_mon +1;
	int day = t->tm_mday;
	std::cout << "year-month-day" << " " << year << " " << month << " " << day << std::endl;
}


int main()
{
	// time_t tp;
	// time(&tp);
	// set_k_time(time(0));
	time_t tp;
	k_time(&tp);


	std::cout << "Iside main:" << std::endl;
	// current_time();

	return 0;
}