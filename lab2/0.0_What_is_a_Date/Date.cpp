#include "date.hpp"
using namespace lab2;


//-----------	CONSTRUCTORS  -------------

//		-- DEFUALT
Date::Date()
{
	debug("Default Constructor Date");	
	
}

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


int Date::current_JDN() const{
    
    //Get current time
    time_t mytime;
	k_time(&mytime);

	//Get local time and date
    struct tm *t = gmtime(&mytime);
    int tmp_year  = t->tm_year + 1900;
    int tmp_month = t->tm_mon + 1;      // months and days
    int tmp_day   = t->tm_mday;         // index from one

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

namespace lab2{
	std::ostream & operator<<(std::ostream & os, const lab2::Date & d)
	{
		os << d.the_year << "-" << d.the_month << "-" << d.the_day;
		return os;
	}	
}






