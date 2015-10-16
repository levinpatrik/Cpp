#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "kattistime.h"

class Date
{
	public:		
		//		--	CONSTRUCTORS  --
		Date();														//Default
		Date(int year, unsigned int month, unsigned int day);		//Value 
		Date(Date const &obj);										//Copy
		~Date();													//Destructor

		//		--  PURE-VIRTUAL FUNCTIONS  --
		unsigned int virtual days_this_month() = 0;
		void virtual add_year() = 0;
		void virtual add_month() = 0;

		//		--  OPERATOR OVERLOAD  --

	protected:
		//		--  ATTRIBUTE  --
		int elapsed_days;
		int the_year;
		unsigned int the_month;
		unsigned int the_day;
		

		//		--  FUNCTIONS  --
		int year();
		unsigned int mod_julian_day();
		unsigned int days_per_week();
		unsigned int week_day();
		unsigned int month();
		unsigned int day();
		std::string week_day_name();
		std::string month_name();
		

};


#endif  