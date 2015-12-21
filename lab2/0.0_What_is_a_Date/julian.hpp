#ifndef JULIAN_H
#define JULIAN_H

#include "date.hpp"

namespace lab2
{
class Julian: public Date
{
	public:
		

		//		--	CONSTRUCTORS  --
		Julian();
		Julian(int year, unsigned int month, unsigned int day):Date(year,month,day){};
		~Julian(){debug("Julian Destructor");};
		Julian(const Date & obj_r);
		Julian(const Date * obj_p);

		
		//		--  OPERATOR OVERLOAD  --
		virtual Julian & operator--() override;
		virtual Julian & operator++() override;
		virtual Julian operator++(int);
		virtual Julian operator--(int);
		virtual Julian & operator+=(int x) override;
		virtual Julian & operator-=(int x) override;
		virtual int operator-(const Date &) const override;


		Julian & operator=(const Date &) override;


		//		--  FUNCTIONS  --
		unsigned int virtual days_this_month() const override;
		void virtual add_year(int) override;
		void virtual add_month(int) override;
		void virtual add_month() override;
		void virtual subtract_month() override;
		int virtual julian_day_number() const override;


	protected:
		//		--  FUNCTIONS  --
		bool is_leap_year() const;
};
}

#endif