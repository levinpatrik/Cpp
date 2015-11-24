#include "Date.h"

//		-- DEFUALT
Date::Date()
{
	debug("Default Constructor Date");	
	time_t mytime = time(0);
	struct tm *t = localtime(&mytime);
	the_year = t->tm_year + 1900;
	the_month = t->tm_mon + 1;
	the_day = t->tm_mday;
	
}

//		-- VALUE
Date::Date(int year, unsigned int month, unsigned int day)
{
	debug("Value Constructor Date");
	//1) Check if yyyy-mm-dd is valid
	the_year 	= year;
	the_month 	= month;
	the_day 	= day;
}

//		-- COPY
Date::Date(Date const &obj)
{
	debug("Copy Constructor Date");

	//Transfer information from obj OBS! maybe wrong representation?
	//to the object being created
}

//		-- DESTRUCTOR
Date::~Date()
{
	//Delete all allocated resources
	debug("DESTRUCTOR Date");
}


unsigned int Date::week_day() const{return 1;}

std::string Date::week_day_name() const{return day_names[week_day()-1];}

std::string Date::month_name() const{return month_names[the_month-1];}

unsigned int Date::mod_julian_day() const{return 0;}



std::vector<int> Date::JDN_2_julian(int JDN) const{

	int y = 4716; int j = 1401; int m = 2; int n = 12; int r = 4; 
	int p = 1461; int v = 3; int u = 5; int s = 153; int w = 2;
	int B = 274277; int c = -38;


	// from wiki!
	int f = JDN + 1401;
	int e = r*f + v;
	int g = std::floor((e % p )/r);
	int h = u*g + w;

	int day = std::floor((h % s)/u) +1;
	int month = std::floor(((h/s)+m) % n) +1;
	int year = std::floor(e /p) - y + std::floor((n + m - month)/n);

	std::vector<int> vec = {year,month,day};
	return vec;
}

std::vector<int> Date::JDN_2_Greg(int JDN) const{

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


std::ostream& operator<<(std::ostream & os, const Date & d)
{

	os << d.year() << "-" << d.month() << "-" << d.day();  
	return os;

}






