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
		Gregorian();													//Default
		Gregorian(int year, unsigned int month, unsigned int day);		//Value
		Gregorian(const Date & obj_r);									//Copy reference
		Gregorian(const Date * obj_p);									//Copy pointer
		~Gregorian(){debug("Gregorian Destructor");};					


		//		--  OPERATOR OVERLOAD  --
		virtual Gregorian &  operator++() override;				
		virtual Gregorian &  operator--() override;
		Gregorian operator++(int);
		Gregorian operator--(int);
		virtual Gregorian &  operator+=(int) override;
		virtual Gregorian &  operator-=(int) override;
		virtual int operator-(const Date &) const override;

		template<typename T> 
		friend class Calender;

		//		--  FUNCTIONS  --
		unsigned int virtual days_this_month() const override;
		void virtual add_year(int) override;
		void virtual add_month() override;
		void virtual add_month(int) override;
		// int virtual julian_day_number() const override;
		int virtual mod_julian_day() const override;

	private:	
		virtual std::vector<int> JDN_2_date(int) const override;
		virtual bool is_leap_year() const override;
		


};
}

#endif