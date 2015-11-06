#include "Date.h"

//		-- DEFUALT
Date::Date()
{
	time_t mytime = time(0);
	struct tm *t = localtime(&mytime);
	the_year = t->tm_year + 1900;
	the_month = t->tm_mon + 1;
	the_day = t->tm_mday;
	std::cout << "year-month-day" << " " << the_year << " " << the_month << " " << the_day << std::endl;
}

//		-- VALUE
Date::Date(int year, unsigned int month, unsigned int day)
{
	std::cout << "day month year given" << std::endl;
	//1) Check if yyyy-mm-dd is valid
	the_year 	= year;
	the_month 	= month;
	the_day 	= day;
}

//		-- COPY
Date::Date(Date const &obj)
{
	std::cout << "this.type: " << this.type << " obj.type " << obj.type << std::endl;
	//Transfer information from obj OBS! maybe wrong representation?
	//to the object being created
}

//		-- DESTRUCTOR
virtual Date::~Date()
{
	//Delete all allocated resources
	std::cout << "Date destructor" << std::endl;
}

unsigned int Date::days_per_week(){return 0;}

unsigned int Date::week_day(){return 0;}

std::string Date::week_day_name(){return "Current day";}

std::string Date::month_name(){return "Current month";}

int Date::year(){return the_year;}

unsigned int Date::month(){return the_month;}

unsigned int Date::day(){return the_day;}

unsigned int Date::mod_julian_day(){return 0;}








