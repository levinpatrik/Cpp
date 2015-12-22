#include "date.hpp"
using namespace lab2;


//-----------	CONSTRUCTORS  -------------

//		-- DEFUALT
Date::Date()
{
	debug("Default Constructor Date");	
	// time_t mytime = time(0);
	// struct tm *t = localtime(&mytime);
	// the_year = t->tm_year + 1900;
	// the_month = t->tm_mon + 1;
	// the_day = t->tm_mday;
	
}

//		-- VALUE
// Date::Date(int year, unsigned int month, unsigned int day)
// {
// 	debug("Value Constructor Date")
// 	the_year 	= year;
// 	the_month 	= month;
// 	the_day 	= day;
// }

// //		-- COPY
// Date::Date(Date const & obj)
// {
// 	debug("Copy Constructor Date reference");
// 	int JDN = obj.julian_day_number();

// }

// Date(Date const * obj_p)
// {
// 	obj_p->debug("Copy Constructor Date ptr");

// }

//		-- DESTRUCTOR
Date::~Date()
{
	//Delete all allocated resources
	debug("DESTRUCTOR Date");
}



//-----------	FUNCTIONS  -------------

unsigned int Date::week_day() const{

	unsigned int JDN = julian_day_number();
	unsigned int weekday_nr = (JDN % 7) + 1;

	return weekday_nr;

}

std::string Date::week_day_name() const{return day_names[week_day()-1];}

std::string Date::month_name() const{return month_names[the_month-1];}

int Date::mod_julian_day() const{
	int JDN = julian_day_number();
	int MJD = JDN - 2400001;
	return MJD;
}



// std::vector<int> Date::JDN_2_date(int JDN) const{

// 	int y = 4716; int j = 1401; int m = 2; int n = 12; int r = 4; 
// 	int p = 1461; int v = 3; int u = 5; int s = 153; int w = 2;
// 	int B = 274277; int c = -38;

// 	// from wiki!
// 	int f = JDN + 1401;
// 	int e = r*f + v;
// 	int g = std::floor((e % p )/r);
// 	int h = u*g + w;

// 	int day = std::floor((h % s)/u) +1;
// 	int month = std::floor(((h/s)+m) % n) +1;
// 	int year = std::floor(e /p) - y + std::floor((n + m - month)/n);

// 	std::vector<int> vec = {year,month,day};
// 	return vec;
// }

// std::vector<int> Date::JDN_2_date(int JDN) const{

// 	int y = 4716; int j = 1401; int m = 2; int n = 12; int r = 4; 
// 	int p = 1461; int v = 3; int u = 5; int s = 153; int w = 2;
// 	int B = 274277; int c = -38;

// 	// from wiki!
// 	int f = JDN + j + std::floor((((4*JDN+B)/146097)*3)/4) +c;
// 	int e = r*f + v;
// 	int g = std::floor((e % p )/r);
// 	int h = u*g + w;

// 	int day = std::floor((h % s)/u) +1;
// 	int month = std::floor(((h/s)+m) % n) +1;
// 	int year = std::floor(e /p) - y + std::floor((n + m - month)/n);

// 	std::vector<int> vec = {year,month,day};
// 	return vec;
// }

// // THIS IS THE CURRENT TIME USED DURING TESTIN!
// // //	returns the current JDN by looking at the time
// int Date::current_JDN() const{

// 	//get current time
// 	debug("current_JDN");
// 	time_t mytime = time(0);
// 	struct tm *t = localtime(&mytime);
// 	int tmp_year = t->tm_year + 1900;
// 	unsigned int tmp_month = t->tm_mon + 1;
// 	unsigned int tmp_day = t->tm_mday;

// 	//transform to JDN (greg->JDN)
// 	int a = std::floor((14 - tmp_month)/12);
// 	int y = tmp_year + 4800 - a;
// 	int m = tmp_month + 12*a -3;
// 	int JDN = tmp_day + std::floor((153*m + 2 )/5) + 365*y + std::floor(y/4)
// 	- std::floor(y/100) + std::floor(y/400) -32045;

// 	return JDN;
// }




//	Attempt on kattis_time
int Date::current_JDN() const{
      // För att få nuvarande tid
    time_t mytime;
	k_time(&mytime);

    // För att få ut datum lokalt 
    struct tm *t = gmtime(&mytime);
    int tmp_year  = t->tm_year + 1900;
    int tmp_month = t->tm_mon + 1;      // månaderna och dagarna
    int tmp_day   = t->tm_mday;         // indexerade från ETT

	//transform to JDN (greg->JDN)
	int a = std::floor((14 - tmp_month)/12);
	int y = tmp_year + 4800 - a;
	int m = tmp_month + 12*a -3;
	int JDN = tmp_day + std::floor((153*m + 2 )/5) + 365*y + std::floor(y/4)
	- std::floor(y/100) + std::floor(y/400) -32045;
	return JDN;
}




//-----------	OPERATORS  -------------
Date & Date::operator=(const Date & d){

	int JDN = d.julian_day_number();
	std::vector<int> v = JDN_2_date(JDN);
	the_year = v[0];  the_month = v[1]; the_day = v[2];
	return *this;
}




// Define operator<<
namespace lab2{
	std::ostream & operator<<(std::ostream & os, const lab2::Date & d)
	{
		os << d.the_year << "-" << d.the_month << "-" << d.the_day;
		return os;
	}	
}






