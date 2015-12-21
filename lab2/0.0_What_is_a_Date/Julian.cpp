#include "julian.hpp"
using namespace lab2;



//		--	CONSTRUCTORS  --
Julian::Julian(){
	debug("Julian default constructor");
	int JDN = current_JDN();
	std::vector<int> v = JDN_2_julian(JDN);
	the_year = v[0]; the_month = v[1]; the_day = v[2];

}



Julian::Julian(const Date & d_r){
	int JDN = d_r.julian_day_number();
	std::vector<int> v = JDN_2_julian(JDN);
	// int tmp_year = v[0]; unsigned int tmp_month = v[1]; unsigned int tmp_day = v[2];
	the_year = v[0]; the_month = v[1];  the_day = v[2];
}


Julian::Julian(const Date * d_p){
	int JDN = d_p->julian_day_number();
	std::vector<int> v = JDN_2_julian(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];
}




//		--  FUNCTIONS  --
unsigned int  Julian::days_this_month() const{
	if (is_leap_year()){
		return days_each_month_leap[the_month-1];
	}
	return days_each_month_normal[the_month - 1];
}

void  Julian::add_year(int n){
	the_year += n;
	if(the_day > days_this_month()){
		the_day = days_this_month();
	}
}

void Julian::add_month(){

	int JDN = julian_day_number();
	JDN += days_this_month();
	std::vector<int> v = JDN_2_julian(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];

}

void  Julian::add_month(int n)
{

	int years = std::floor(n/12);
	the_year += years;
	int months = n - (years*12);

	if(n < 0)
	{
		for(int i = 0; i < abs(months); i++)
		{
			the_month--;
			if(the_month < 1)
			{
				the_year--;
				the_month = 12;
			}
		}
	}
	else
	{
		for(int i = 0; i < months; i++)
		{
			the_month++;
			if(the_month > 12)
			{
				the_year++; the_month = 1;
			}
		}
	}
	if(the_day > days_this_month())
	{
		the_day = days_this_month();
	}
}


bool Julian::is_leap_year() const{

	if (the_year % 4 == 0){
		return true;
	}
	return false;
}

int Julian::julian_day_number() const{

	int a = std::floor((14 - the_month)/12);
	int y = the_year + 4800 - a;
	int m = the_month + 12*a -3;

	int JDN = the_day + std::floor((153*m + 2 )/5) + 365*y + std::floor(y/4) -32083;
	return JDN;
}


//		--  OPERATOR OVERLOAD  --
Julian & Julian::operator++(){

	if(the_day < days_this_month())
	{
		the_day++;
	}
	else if(the_day == days_this_month())
	{
		if(the_month == 12)
		{
			the_year++; the_month = 1; the_day = 1;
		}
		else
		{
			the_month++; the_day = 1;
		}
	}
	return *this;
}

Julian & Julian::operator--(){

	if(the_day > 1){
		the_day--;
	}
	else if(the_day == 1){
		if(the_month == 1){
			the_year--; the_month = 12; the_day = days_this_month();
		}
		else{
			the_month--; the_day = days_this_month();
		}
	}
	return *this;
}

// Postfix ++
Julian Julian::operator++(int)
{
	Julian tmp(the_year, the_month, the_day);
	++(*this);
	return tmp;
}

// Postfix --
Julian Julian::operator--(int)
{
	Julian tmp(the_year, the_month, the_day);
	--(*this);
	return tmp;
}

Julian & Julian::operator+=(int x){


	int JDN = julian_day_number();
	JDN += x;
	std::vector<int> v = JDN_2_julian(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];
	return *this;


}

Julian & Julian::operator-=(int x){


	int JDN = julian_day_number();
	JDN -= x;
	std::vector<int> v = JDN_2_julian(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];
	return *this;

}



int Julian::operator-(const Date & g) const
{
	int JDN1 = julian_day_number();
	int JDN2 = g.julian_day_number();
	return (JDN1 - JDN2);
}

Julian & Julian::operator=(const Date & d)
{
	debug("inne i operator = Julian");
	if (this != &d)
	{	
		int JDN = d.julian_day_number();
		std::vector<int> v = d.JDN_2_julian(JDN);
		the_year = v[0]; the_month = v[1]; the_day = v[2];
	}
	return *this;
}










