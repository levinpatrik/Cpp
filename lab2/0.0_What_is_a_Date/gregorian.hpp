#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "date.hpp"
using namespace lab2;

namespace lab2
{
class Gregorian: public Date
{
	public:

		//		--	CONSTRUCTORS  --
		Gregorian();																		//Default
		Gregorian(int year, unsigned int month, unsigned int day):Date(year,month,day){};	//Value
		Gregorian(const Date & obj_r);
		Gregorian(const Date * obj_p);
		~Gregorian(){debug("Gregorian Destructor");};


		//		--  OPERATOR OVERLOAD  --
		virtual Gregorian &  operator++() override;				
		virtual Gregorian &  operator--() override;
		Gregorian operator++(int);
		Gregorian operator--(int);
		virtual Gregorian &  operator+=(int x) override;
		virtual Gregorian &  operator-=(int x) override;
		virtual int operator-(const Date &) const override;

		Gregorian & operator=(const Date &) override;

		//		--  FUNCTIONS  --
		unsigned int virtual days_this_month() const override;
		void virtual add_year(int) override;
		void virtual add_month(int) override;
		void virtual add_month() override;
		void virtual subtract_month() override;
		int virtual julian_day_number() const override;

	protected:	
		bool is_leap_year() const;
		

};
}

#endif