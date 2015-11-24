#ifndef JULIAN_H
#define JULIAN_H

#include "Date.h"

class Julian: public Date
{
	public:
		

		//		--	CONSTRUCTORS  --
		Julian():Date(){};
		Julian(int year, unsigned int month, unsigned int day):Date(year,month,day){};
		~Julian(){debug("Julian Destructor");};
		
		//		--  OPERATOR OVERLOAD  --
		virtual Julian & operator--();
		virtual Julian & operator++();
		Julian operator++(int);
		Julian operator--(int);
		virtual Julian & operator+=(unsigned int x);
		virtual Julian & operator-=(unsigned int x);

		int operator-(const Date & g);

		Julian & operator=(const Date &);


		//		--  FUNCTIONS  --
		unsigned int virtual days_this_month() const;
		void virtual add_year(int);
		void virtual add_month(int);
		bool is_leap_year() const;
		int virtual julian_day_number() const;


	private:
		//		--  FUNCTIONS  --
		//		--  ATTRIBUTE  --
};

#endif