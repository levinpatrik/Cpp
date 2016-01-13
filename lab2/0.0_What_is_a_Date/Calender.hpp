#ifndef CALENDER_H
#define CALENDER_H

#include <map>
#include <iostream>
#include <string.h>
#include "Date.hpp"
// #include <utility>

namespace lab2{
template<typename T>
class Calender{

public:
	//CONSTRUCTORS
	Calender();
	Calender(const Date & d);

	template<typename T2>
	Calender(const Calender<T2> & c);


	//FUNCTIONS
	bool set_date(int, int, int);
	bool add_event(std::string, int, int, int);
	bool add_event(std::string, int, int);
	bool add_event(std::string, int);
	bool add_event(std::string);
	bool remove_event(std::string, int, int, int);
	bool remove_event(std::string, int, int);
	bool remove_event(std::string, int);
	bool remove_event(std::string);

	// Become friends with operator<<
	//You have to redeclare the template for non-member functions
	template<typename T2>
	friend std::ostream & operator<<(std::ostream & os, Calender<T2> & c);

	//You are not autoatically "friend" with class calender with another T 
	template<typename T2>
	friend class Calender;

protected:
	std::multimap<unsigned long int,std::string> m;
	std::pair<std::multimap<unsigned long int, std::string>::iterator, std::multimap<unsigned long int, std::string>::iterator> itr_pair;

	//Change this? wound be current date in one day...
	T date_obj;

};


//-----		CONSTRUCTORS   ------
template<typename T>
Calender<T>::Calender(){

	T todays_date;
	T date_obj = todays_date;

}


//Remove?
template<typename T>
Calender<T>::Calender(const Date & d){

	int year, month, day;
	int JDN = d.mod_julian_day();
	std::vector<int> v = date_obj.JDN_2_date(JDN);
	year = v[0]; month = v[1]; day = v[2];
	date_obj.the_year = year;
	date_obj.the_month = month;
	date_obj.the_day = day;

}


template<typename T>
template<typename T2>
Calender<T>::Calender(const Calender<T2> & c){

	int year, month, day;
	int JDN = c.date_obj.mod_julian_day();
	std::vector<int> v = date_obj.JDN_2_date(JDN);
	year = v[0]; month = v[1]; day = v[2];
	date_obj.the_year = year;
	date_obj.the_month = month;
	date_obj.the_day = day;



}

	

template<typename T2>
std::ostream & operator<<(std::ostream & os, Calender<T2> & c)
{

	int year,month,day;
	for(std::multimap<unsigned long int, std::string>::iterator	it = c.m.begin(); it != c.m.end(); it++)
	{
		year = (*it).first/10000;
		month = ((*it).first - year*10000)/100;
		day = ((*it).first - year*10000) - month*100;

		if ((*it).first >= (c.date_obj.year()*10000 + c.date_obj.month()*100 + c.date_obj.day()))
		{
			std::cout << std::endl;

			os << "BEGIN:VCALENDAR" << std::endl;
			os << "BEGIN:VEVENT" << std::endl;

			os << "DTSTART:" << year;
			if(month > 0 && month < 10)
				os << "0";
			os << month;
			if(day > 0 && day < 10)
				os << "0";
			os << day;
			os << "T000000Z" << std::endl;

			day++;
			os << "DTEND:" << year;
			if(month > 0 && month < 10)
				os << "0";
			os << month;
			if(day > 0 && day < 10)
				os << "0";
			os << day;
			os << "T000000Z" << std::endl;

			os << "SUMMARY:" << (*it).second << std::endl;
			os << "END:VEVENT" << std::endl;
			os << "END:VCALENDAR" << std::endl;


		}
	}

	return os;
}




template<typename T>
bool Calender<T>::set_date(int day, int month, int year){

	try
	{
		T date_tmp(year,month,day);
		date_obj.the_year = date_tmp.year();
		date_obj.the_month = date_tmp.month();
		date_obj.the_day = date_tmp.day();
	}
	catch(std::invalid_argument & s)
	{
		return false;
	}

	return true;

}


template<typename T>
bool Calender<T>::add_event(std::string s, int day, int month, int year){

	//Validate date
	try{ T date_tmp(year,month,day); }
	catch(std::invalid_argument & s){return false;}

	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			// std::cout << "Same event found, no event added. " << std::endl;	
			return false;
		}
		// std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}

	m.insert(std::pair<unsigned long int, std::string>(key, s));
	return true;
}

template<typename T>
bool Calender<T>::add_event(std::string s, int day, int month)
{
	int year = date_obj.year();
	return Calender<T>::add_event(s,  year,  month,  day);

}


template<typename T>
bool Calender<T>::add_event(std::string s, int day)
{
	int year = date_obj.year();
	int month = date_obj.month();
	return Calender<T>::add_event(s,  year,  month,  day);

}

template<typename T>
bool Calender<T>::add_event(std::string s)
{
	int year = date_obj.year();
	int month = date_obj.month();
	int day = date_obj.day();
	return Calender<T>::add_event(s,  year,  month,  day);


}


template<typename T>
bool Calender<T>::remove_event(std::string s, int day, int month, int year){

	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			m.erase(it);
			return true;
		}
	}
	return false;
}

template<typename T>
bool Calender<T>::remove_event(std::string s, int day, int month)
{
	int year = date_obj.year();
	return Calender<T>::remove_event(s, year, month, day);

}
template<typename T>
bool Calender<T>::remove_event(std::string s, int day)
{
	int year = date_obj.year();
	int month = date_obj.month();
	return Calender<T>::remove_event(s, year, month, day);

}
template<typename T>
bool Calender<T>::remove_event(std::string s)
{
	int year = date_obj.year();
	int month = date_obj.month();
	int day = date_obj.day();
	return Calender<T>::remove_event(s, year, month, day);

}




}	// end namespace
#endif