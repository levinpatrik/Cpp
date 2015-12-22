#ifndef JULIAN_H
#define JULIAN_H
#include "date.hpp"
#include "gregorian.hpp"


// using namespace lab2;
namespace lab2
{
class Julian: public Date
{
	public:
		

		//		--	CONSTRUCTORS  --
		Julian();
		// Julian(int year, unsigned int month, unsigned int day):Date(year,month,day){};
		Julian(int year, unsigned int month, unsigned int day);
		Julian(const Date & obj_r);
		Julian(const Date * obj_p);
		~Julian(){debug("Julian Destructor");};

		
		//		--  OPERATOR OVERLOAD  --
		virtual Julian & operator--() override;
		virtual Julian & operator++() override;
		virtual Julian operator++(int);
		virtual Julian operator--(int);
		virtual Julian & operator+=(int x) override;
		virtual Julian & operator-=(int x) override;
		virtual int operator-(const Date &) const override;
		virtual std::vector<int> JDN_2_date(int) const override;
		
		// virtual Julian & operator=(const Date &) override;
		// Julian & operator=(const Julian & j);
		// Julian & operator=(const Date & d);


		//		--  FUNCTIONS  --
		unsigned int virtual days_this_month() const override;
		void virtual add_year(int) override;
		void virtual add_month() override;
		void virtual add_month(int) override;
		int virtual julian_day_number() const override;


		bool is_leap_year() const;
	protected:
		//		--  FUNCTIONS  --
};
}

#endif