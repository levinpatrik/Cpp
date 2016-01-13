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
		assert(c.set_date(10,10,2000) == 1);
		assert(c.set_date(-10,10,2000) == 0);
		assert(c.set_date(10,100,2000) == 0);
	}

	cout <<"--- Testing add_event(str,int,int,int) -= ---" << endl;
	{
		Calender<Gregorian> c;
		c.add_event("test event1",10,10,2000);
		c.add_event("test event2",10,10,2010);
		c.add_event("test event3",10,10,2010);
		assert(c.add_event("test event2",10,10,2010) == 0);

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
		c.add_event("test event1",10,10,2010);
		c.add_event("test event2",10,10,2010);
		c.add_event("test event3",10,10,2010);
		c.add_event("test event4",1,1,2015);

		c.add_event("test event5",1,12,2017);
		c.add_event("test event5.2",1,12,2017);
		c.add_event("test event5.3",1,12,2017);
		c.add_event("test event5",1,12,2017);
		c.add_event("test event5",1,12,2017);
		c.add_event("test event6",12,1,2020);
		c.add_event("test event7",20,4,2099);
		cout << c << endl;

	}

	cout <<"--- Testing Copyconstructor(Date) ---" << endl;
	{

		Gregorian g(2010,10,10);
		Calender<Gregorian> g3(g);
		cout << g3 << endl;

		Julian j1(2010,10,10);
		Calender<Gregorian> cj(j1);
		cout << cj << endl;


	}

	cout <<"--- Testing Copyconstructor(Calender) ---" << endl;
	{

		Calender<Julian> j1;
		j1.set_date(2010,10,10);
		Calender<Julian> j2(j1);
		assert(j2.set_date(10,10,2010) == 1);

		Calender<Gregorian> g1(j1);
		assert(g1.set_date(23,10,2010) == 1);

		Calender<Julian> j3(g1);
		assert(j1.set_date(10,10,2010) == 1);


	}

	cout <<"--- Testing remove_event ---" << endl;
	{

		Calender<Gregorian> j;
		j.add_event("test event1",10,10,2030);
		j.add_event("test event2",10,10,2030);
		j.add_event("test event3",10,10,2030);
		j.add_event("test event4",10,10,2030);
		j.remove_event("test event1",10,10,2030);
		j.remove_event("test event4",10,10,2030);
		cout<< "J1 " << endl << j;


		Calender<Gregorian> j2;
		// j2.set_date(2016,1,4);
		j2.add_event("Test event1", 10,10);
		j2.add_event("Test event2", 10,10);
		j2.remove_event("Test event2", 10,10);
		cout<< "J2 " << endl << j2;

		Calender<Gregorian> j3;
		j3.set_date(2016,1,10);
		j3.add_event("Test event1", 10);
		j3.add_event("Test event2", 10);
		j3.remove_event("Test event2", 10);
		cout<< "J3 " << endl << j3;
	}











	cout << "ALL TEST OK" << endl;
	return 0;
}