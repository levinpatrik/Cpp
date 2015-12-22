#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "date.hpp"
#include "julian.hpp"

// using namespace lab2;
namespace lab2
{
class Gregorian: public Date
{
	public:

		//		--	CONSTRUCTORS  --
		Gregorian();																		//Default
		// Gregorian(int year, unsigned int month, unsigned int day):Date(year,month,day){};	//Value
		Gregorian(int year, unsigned int month, unsigned int day);
		Gregorian(const Date & obj_r);
		Gregorian(const Date * obj_p);
		~Gregorian(){debug("Gregorian Destructor");};


		//		--  OPERATOR OVERLOAD  --
		virtual Gregorian &  operator++() override;				
		virtual Gregorian &  operator--() override;
		Gregorian operator++(int);
		Gregorian operator--(int);
		virtual Gregorian &  operator+=(int) override;
		virtual Gregorian &  operator-=(int) override;
		virtual int operator-(const Date &) const override;

		// virtual Gregorian & operator=(const Date &) override;
		// Gregorian & operator=(const Date &);

		// Gregorian & operator=(const Date &);
		// Gregorian & operator=(const Gregorian &);

		//		--  FUNCTIONS  --
		unsigned int virtual days_this_month() const override;
		void virtual add_year(int) override;
		void virtual add_month() override;
		void virtual add_month(int) override;
		int virtual julian_day_number() const override;
		virtual std::vector<int> JDN_2_date(int) const override;

		bool is_leap_year() const;
	protected:	
		

};
}

#endif