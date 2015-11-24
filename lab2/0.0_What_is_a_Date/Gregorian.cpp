#include "Gregorian.h"

unsigned int  Gregorian::days_this_month() const{
	if (is_leap_year()){
		return days_each_month_leap[the_month-1];
	}
	return days_each_month_normal[the_month - 1];
}

void  Gregorian::add_year(int n){
	the_year += n;
	if(the_day > days_this_month()){
		the_day = days_this_month();
	}
}

void  Gregorian::add_month(int n){

	int years = std::floor(n/12);
	int months = n % 12;

	if((the_month + months) < 12){
		the_month += months;
	}
	else{
		the_year++; 
		the_month = (the_month + months) % 12;
	}

	the_year += years;
	if(the_day > days_this_month()){
		the_day = days_this_month();
	}
}

bool Gregorian::is_leap_year() const{

	if (the_year % 4 == 0){
		if(!(the_year % 100 == 0) || (the_year % 400  == 0)){
			return true;
		}
	}
	return false;
}

int Gregorian::julian_day_number() const{

	int a = std::floor((14 - the_month)/12);
	int y = the_year + 4800 - a;
	int m = the_month + 12*a -3;

	int JDN = the_day + std::floor((153*m + 2 )/5) + 365*y + std::floor(y/4)
	- std::floor(y/100) + std::floor(y/400) -32045;
	return JDN;
}


Gregorian & Gregorian::operator++(){

	debug("inside Greg++");
	if(the_day < days_this_month()){
		the_day++;
	}
	else if(the_day == days_this_month()){
		if(the_month == 12){
			the_year++; the_month = 1; the_day = 1;
		}
		else{
			the_month++; the_day = 1;
		}
	}
	return *this;
}

Gregorian & Gregorian::operator--(){

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
Gregorian Gregorian::operator++(int)
{
	Gregorian tmp(the_year, the_month, the_day);
	++(*this);
	return tmp;
}

// Postfix --
Gregorian Gregorian::operator--(int)
{
	Gregorian tmp(the_year, the_month, the_day);
	--(*this);
	return tmp;
}



Gregorian & Gregorian::operator+=(unsigned int x){
	while(x > 0)
	{
		if((the_day + x) > days_this_month())
		{
			x -= (days_this_month() - the_day);
			if(the_month == 12)
			{
				the_year++; the_month = 1; the_day = 1;
			}
			else{
				the_month++; the_day = 1;
			}
		}
		else
		{
			the_day += x;
			x = 0;
		}
	}
	return *this;
}

Gregorian & Gregorian::operator-=(unsigned int x){
	while(x > 0)
	{
		if((the_day - x) < 1)
		{
			x -= the_day; 
			if(the_month == 1)
			{
				the_year--; the_month = 12; the_day = days_this_month();
			}
			else
			{
				the_month--; the_day = days_this_month();
			}
		}
		else
		{
			the_day -= x; x = 0;
		}
	}
	return *this;
}

int Gregorian::operator-(const Date & g)
{
	int JDN1 = julian_day_number();
	int JDN2 = g.julian_day_number();
	return (JDN1 - JDN2);
}

Gregorian & Gregorian::operator=(const Date & d)
{
	int JDN = d.julian_day_number();
	std::vector<int> v = d.JDN_2_Greg(JDN);
	the_year = v[0]; the_month = v[1]; the_day = v[2];
	return *this;
}
