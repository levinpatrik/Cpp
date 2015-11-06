#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "Date.h"

class Gregorian: Date
{
	public:
		int type = 2;
		Gregorian():Date(){};
		~Gregorian(){std::cout<< "Gregorian Destructor" << std::endl;};
		// unsigned int virtual days_this_month();
		// void virtual add_year();
		// void virtual add_month();

	private:
			
};

#endif