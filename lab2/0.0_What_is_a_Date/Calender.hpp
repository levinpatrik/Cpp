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
	// friend std::ostream & operator<<(std::ostream & os, const Calender<T> & c);


protected:
	std::multimap<unsigned long int,std::string> m;
	std::pair<std::multimap<unsigned long int, std::string>::iterator, std::multimap<unsigned long int, std::string>::iterator> itr_pair;
	T date_obj;

};


// template<typename T>
// std::ostream & operator<<(std::ostream & os, const Calender<T> & c)
// {
// 	os << c.date_obj.year()<< "-" << c.date_obj.month() << "-" << c.date_obj.day();
// 	return os;
// }	



template<typename T>
bool Calender<T>::set_date(int year, int month, int day){

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
bool Calender<T>::add_event(std::string s, int year, int month, int day){

	//Validate date
	try{ T date_tmp(year,month,day); }
	catch(std::invalid_argument & s){return false;}

	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			return false;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}

	m.insert(std::pair<unsigned long int, std::string>(key, s));
	return true;
}



template<typename T>
bool Calender<T>::add_event(std::string s, int month, int day){

	int year = date_obj.year();
	//Validate date
	try{ T date_tmp(year,month,day); }
	catch(std::invalid_argument & s){return false;}

	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			return false;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}

	m.insert(std::pair<unsigned long int, std::string>(key, s));
	return true;
}


template<typename T>
bool Calender<T>::add_event(std::string s, int day){

	int year = date_obj.year();
	int month = date_obj.month();
	//Validate date
	try{ T date_tmp(year,month,day); }
	catch(std::invalid_argument & s){return false;}

	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			return false;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}

	m.insert(std::pair<unsigned long int, std::string>(key, s));
	return true;
}


template<typename T>
bool Calender<T>::add_event(std::string s){

	int year = date_obj.year();
	int month = date_obj.month();
	int day = date_obj.day();

	//Validate date
	try{ T date_tmp(year,month,day); }
	catch(std::invalid_argument & s){return false;}

	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			return false;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}

	m.insert(std::pair<unsigned long int, std::string>(key, s));
	return true;
}


template<typename T>
bool Calender<T>::remove_event(std::string s, int year, int month, int day){

	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			m.erase(it);
			return true;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}
	return false;
}


template<typename T>
bool Calender<T>::remove_event(std::string s, int month, int day){

	int year = date_obj.year();
	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			m.erase(it);
			return true;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}
	return false;
}

template<typename T>
bool Calender<T>::remove_event(std::string s, int day){

	int year = date_obj.year();
	int month = date_obj.month();
	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			m.erase(it);
			return true;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}
	return false;
}


template<typename T>
bool Calender<T>::remove_event(std::string s){

	int year = date_obj.year();
	int month = date_obj.month();
	int day = date_obj.day();
	unsigned long int key = year*10000 + month*100 + day;
	itr_pair = m.equal_range(key);
	for(std::multimap<unsigned long int, std::string>::iterator it = itr_pair.first; it != itr_pair.second; ++it)
	{
		if(s == (*it).second)
		{
			m.erase(it);
			return true;
		}
		std::cout << "  [" << (*it).first << ", " << (*it).second << "]" << std::endl;
	}
	return false;
}

}	// end namespace
#endif