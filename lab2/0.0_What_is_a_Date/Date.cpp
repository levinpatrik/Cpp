#include "Date.h"

//		-- DEFUALT
Date::Date()
{
	
	//initialize the calander with the current date.
}

//		-- VALUE
Date::Date(int year, unsigned int month, unsigned int day)
{
	//1) Check if yyyy-mm-dd is valid
	the_year 	= year;
	the_month 	= month;
	the_day 	= day;
}

//		-- COPY
Date::Date(Date const &obj)
{
	//Transfer information from obj OBS! maybe wrong representation?
	//to the object being created
}

//		-- DESTRUCTOR
Date::~Date()
{
	//Delete all allocated resources
}

unsigned int Date::days_per_week(){return 0;}

unsigned int Date::week_day(){return 0;}

std::string Date::week_day_name(){return "Current day";}

std::string Date::month_name(){return "Current month";}

int Date::year(){return the_year;}

unsigned int Date::month(){return the_month;}

unsigned int Date::day(){return the_day;}

unsigned int mod_julian_day(){return 0;}








