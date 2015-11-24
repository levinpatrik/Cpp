#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "Date.h"

class Gregorian: public Date
{
	public:

		//		--	CONSTRUCTORS  --
		Gregorian():Date(){};																//Default
		Gregorian(int year, unsigned int month, unsigned int day):Date(year,month,day){};	//Value
		~Gregorian(){debug("Gregorian Destructor");};

		//		--  OPERATOR OVERLOAD  --
		virtual Gregorian &  operator++();				
		virtual Gregorian &  operator--();
		Gregorian operator++(int);
		Gregorian operator--(int);
		virtual Gregorian &  operator+=(unsigned int x);
		virtual Gregorian &  operator-=(unsigned int x);

		int operator-(const Date &);
		Gregorian & operator=(const Date &);

		//		--  FUNCTIONS  --
		unsigned int virtual days_this_month() const;
		void virtual add_year(int);
		void virtual add_month(int);
		bool is_leap_year() const;
		int virtual julian_day_number() const;


	private:	

		

};

#endif