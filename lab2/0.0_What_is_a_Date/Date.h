#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "kattistime.h"
#include <string>
#include <cmath>
#include <vector>


class Date
{
	public:		
		//For debugging only, remove later
		void debug(std::string str){// std::cout << str << std::endl
			;}

		//		--	CONSTRUCTORS  --
		Date();														//Default
		Date(int year, unsigned int month, unsigned int day);		//Value 
		Date(Date const &obj);										//Copy
		virtual ~Date();											//Destructor

		//		--  PURE-VIRTUAL FUNCTIONS  --
		unsigned int virtual days_this_month() const = 0;
		void virtual add_year(int) = 0;
		void virtual add_month(int) = 0;
		int virtual julian_day_number() const = 0;

		//		--  OPERATOR OVERLOAD  --
		virtual Date & operator++() = 0;					// prefix
		virtual Date & operator--() = 0;					// prefix	
		virtual Date & operator+=(unsigned int x) = 0;
		virtual Date & operator-=(unsigned int x) = 0;
		virtual Date & operator=(const Date &) = 0;

		bool operator==(const Date & d){ return this->julian_day_number() == d.julian_day_number();}
		bool operator!=(const Date & d){ return this->julian_day_number() != d.julian_day_number();}
		bool operator< (const Date & d){ return this->julian_day_number() <  d.julian_day_number();}
		bool operator> (const Date & d){ return this->julian_day_number() >  d.julian_day_number();}
		bool operator<=(const Date & d){ return this->julian_day_number() <= d.julian_day_number();}
		bool operator>=(const Date & d){ return this->julian_day_number() >= d.julian_day_number();}

		friend std::ostream & operator<<(std::ostream & , const Date &);

		//		--  FUNCTIONS  --
		unsigned int mod_julian_day() const;
		unsigned int week_day() const ;
		std::string week_day_name() const;
		std::string month_name() const;
		unsigned int days_per_week() const{return 7;};
		unsigned int day() const {return the_day;}
		unsigned int month() const {return the_month;}
		int year() const{return the_year;}; 

		std::vector<int> JDN_2_Greg(int) const;
		std::vector<int> JDN_2_julian(int) const;


	protected:
		//		--  ATTRIBUTE  --
		int elapsed_days;
		int the_year;
		unsigned int the_month;
		unsigned int the_day;
		std::string day_names[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		std::string month_names[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		int days_each_month_normal[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		int days_each_month_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
};


#endif  