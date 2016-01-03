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

	cout <<"--- Testing add_event(str,int,int,int) -= ---" << endl;
	{
		Calender<Gregorian> c;
		c.add_event("test event1",2010,10,10);
		c.add_event("test event2",2010,10,10);
		c.add_event("test event3",2010,10,10);
		assert(c.add_event("test event2",2010,10,10) == 0);

	}

	cout <<"--- Testing add_event(str,int,int) -= ---" << endl;
	{
		Calender<Gregorian> c;
		c.add_event("test event1",10,10);
		c.add_event("test event2",10,10);
		c.add_event("test event3",10,10);
		assert(c.add_event("test event2",10,10) == 0);

	}


	cout <<"--- Testing add_event(str,int) -= ---" << endl;
	{
		Calender<Gregorian> c;
		c.add_event("test event1",10);
		c.add_event("test event2",10);
		c.add_event("test event3",10);
		assert(c.add_event("test event2",10) == 0);

	}

	cout <<"--- Testing add_event(str) -= ---" << endl;
	{
		Calender<Gregorian> c;
		c.add_event("test event1");
		c.add_event("test event2");
		c.add_event("test event3");
		assert(c.add_event("test event2") == 0);

	}


	cout <<"--- Testing << -= ---" << endl;
	{
		Calender<Gregorian> c;
		c.add_event("test event1",2010,10,10);
		c.add_event("test event2",2010,10,10);
		c.add_event("test event3",2010,10,10);
		c.add_event("test event4",2015,1,1);

		c.add_event("test event5",2017,12,1);
		c.add_event("test event5.2",2017,12,1);
		c.add_event("test event5.3",2017,12,1);
		c.add_event("test event5",2017,12,1);
		c.add_event("test event5",2017,12,1);
		c.add_event("test event6",2020,1,12);
		c.add_event("test event7",2099,4,20);
		cout << c << endl;

	}

	cout <<"--- Testing Copyconstructor ---" << endl;
	{

		Gregorian g(2010,10,10);
		Calender<Gregorian> g3(g);
		cout << g3 << endl;

		Julian j1(2010,10,10);
		Calender<Gregorian> cj(j1);
		cout << cj << endl;


	}











	cout << "ALL TEST OK" << endl;
	return 0;
}