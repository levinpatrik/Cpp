#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "kattistime.h"
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

namespace lab2
{
class Date
{
	//TODO  1) is operator+= able to be in base class?


	public:		
		//For debugging only, remove later
		void debug(std::string str) const{
			// std::cout << str << std::endl
			;}

		//		--	CONSTRUCTORS  --
		Date();														//Default
		virtual ~Date();											//Destructor


		//		--  PURE-VIRTUAL FUNCTIONS  --
		void virtual add_month(int) = 0;
		unsigned int virtual days_this_month() const = 0;
		void virtual add_year(int) = 0;
		void virtual add_month() = 0;
		int virtual julian_day_number() const = 0;


		//		--  OPERATOR OVERLOAD  --
		virtual Date & operator++() = 0;					// prefix
		virtual Date & operator--() = 0;					// prefix
		virtual Date & operator+=(int x) = 0;		
		virtual Date & operator-=(int x) = 0;
		virtual int operator-(const Date &) const = 0;
		Date & operator=(const Date &);


		bool operator==(const Date & d) const { return this->julian_day_number() == d.julian_day_number();}
		bool operator!=(const Date & d) const { return this->julian_day_number() != d.julian_day_number();}
		bool operator< (const Date & d) const { return this->julian_day_number() <  d.julian_day_number();}
		bool operator> (const Date & d) const { return this->julian_day_number() >  d.julian_day_number();}
		bool operator<=(const Date & d) const { return this->julian_day_number() <= d.julian_day_number();}
		bool operator>=(const Date & d) const { return this->julian_day_number() >= d.julian_day_number();}

		// Become friends with operator<<
		friend std::ostream & operator<<(std::ostream & os, const Date & d);
		template<typename T> 
		friend class Calender;

		//		--  FUNCTIONS  --
		int mod_julian_day() const;
		unsigned int week_day() const;
		std::string week_day_name() const;
		std::string month_name() const;
		unsigned int days_per_week() const{return 7;};
		unsigned int months_per_year() const{return 12;};
		unsigned int day() const {return the_day;}
		unsigned int month() const {return the_month;}
		int year() const{return the_year;}; 


	protected:
		//	HELP FUNCTIONS
		int current_JDN() const;
		virtual std::vector<int> JDN_2_date(int) const = 0;
		virtual bool is_leap_year() const = 0;

		// DATA MEMBERS
		int const  days_each_month_normal[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		int const days_each_month_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
		const std::string day_names[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
		const std::string month_names[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
		
		//		--  ATTRIBUTE  --
		int the_year;
		unsigned int the_month;
		unsigned int the_day;

	private:
};
std::ostream & operator<<(std::ostream & os, const Date & d);
}	//end of namespace lab2;

#endif  





