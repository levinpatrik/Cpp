#include <string.h>
#include <iostream>
#include <map>
#include <utility>
#include "Calender.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include <assert.h>   


using namespace lab2;
using namespace std;

int main(){

	time_t mytime = time(0);
    set_k_time(mytime);



	cout <<"--- Testing set_date() -= ---" << endl;
	{
		Calender<Gregorian> c;
		assert(c.set_date(2000,10,10) == 1);
		assert(c.set_date(2000,10,-10) == 0);
		assert(c.set_date(2000,100,10) == 0);
	}

	cout <<"--- Testing add_event(int,int,int) -= ---" << endl;
	{
		Calender<Gregorian> c;
		c.add_event("test event1",2010,10,10);
		c.add_event("test event2",2010,10,10);
		c.add_event("test event3",2010,10,10);
		assert(c.add_event("test event2",2010,10,10) == 0);

	}






	// cout <<"--- Testing << -= ---" << endl;
	// {
	// 	Calender<Gregorian> c;
	// 	cout << c << endl;
	// }

	cout << "ALL TEST OK" << endl;
	return 0;
}