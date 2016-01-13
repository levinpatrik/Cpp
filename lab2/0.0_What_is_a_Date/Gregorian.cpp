#include "gregorian.hpp"
using namespace lab2;


//		------- 	CONSTRUCTORS  --------
Gregorian::Gregorian(){
	int JDN = current_JDN();
	std::vector<int> v = JDN_2_date(JDN);
	the_year = v[0]; the_month = v[1]; the_day = v[2];
}

Gregorian::Gregorian(const Date & d_r){
	int JDN = d_r.mod_julian_day();
	std::vector<int> v = JDN_2_date(JDN);
	the_year = v[0]; the_month = v[1]; the_day = v[2];
}


Gregorian::Gregorian(const Date * d_p){
	int JDN = d_p->mod_julian_day();
	std::vector<int> v = JDN_2_date(JDN);
	the_year = v[0]; the_month = v[1]; the_day = v[2];
}

Gregorian::Gregorian(int year, unsigned int month, unsigned int day){
	the_year = year;
	if(month > 0 && month < 13)
	{
		the_month = month;
		if(day > 0 && day <= days_this_month())
		{
			the_day = day;
		}
		else{
			throw std::invalid_argument( "received invalid day" );
		}
	}
	else{
		throw std::invalid_argument( "received invalid month" );
	}
}




//		------- 	FUNCTIONS  --------
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


void Gregorian::add_month(){

	int JDN = mod_julian_day();
	JDN += days_this_month();
	std::vector<int> v = JDN_2_date(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];
}

void  Gregorian::add_month(int n)
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



bool Gregorian::is_leap_year() const{

	if (the_year % 4 == 0){
		if(!(the_year % 100 == 0) || (the_year % 400  == 0)){
			return true;
		}
	}
	return false;
}

int Gregorian::mod_julian_day() const{

	int a = std::floor((14 - the_month)/12);
	int y = the_year + 4800 - a;
	int m = the_month + 12*a -3;

	//REMOVE 240001
	int JDN = the_day + std::floor((153*m + 2 )/5) + 365*y + std::floor(y/4)
	- std::floor(y/100) + std::floor(y/400) -32045-2400001;
	return JDN;
}






// int Gregorian::julian_day_number() const{

// 	int a = std::floor((14 - the_month)/12);
// 	int y = the_year + 4800 - a;
// 	int m = the_month + 12*a -3;

// 	int JDN = the_day + std::floor((153*m + 2 )/5) + 365*y + std::floor(y/4)
// 	- std::floor(y/100) + std::floor(y/400) -32045;
// 	return JDN;
// }

std::vector<int> Gregorian::JDN_2_date(int JDN) const{

	JDN = JDN + 2400001;
	int y = 4716; int j = 1401; int m = 2; int n = 12; int r = 4; 
	int p = 1461; int v = 3; int u = 5; int s = 153; int w = 2;
	int B = 274277; int c = -38;

	// from wiki!
	int f = JDN + j + std::floor((((4*JDN+B)/146097)*3)/4) +c;
	int e = r*f + v;
	int g = std::floor((e % p )/r);
	int h = u*g + w;

	int day = std::floor((h % s)/u) +1;
	int month = std::floor(((h/s)+m) % n) +1;
	int year = std::floor(e /p) - y + std::floor((n + m - month)/n);

	std::vector<int> vec = {year,month,day};
	return vec;
}








//------- 	OPERATORS  --------
Gregorian & Gregorian::operator++(){

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



Gregorian & Gregorian::operator+=(int x){


	int JDN = mod_julian_day();
	JDN += x;
	std::vector<int> v = JDN_2_date(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];
	return *this;

}

Gregorian & Gregorian::operator-=(int x){

	int JDN = mod_julian_day();
	JDN -= x;
	std::vector<int> v = JDN_2_date(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];
	return *this;


}

int Gregorian::operator-(const Date & g) const
{
	int JDN1 = mod_julian_day();
	int JDN2 = g.mod_julian_day();
	return (JDN1 - JDN2);
}
