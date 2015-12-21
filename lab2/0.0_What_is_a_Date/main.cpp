#include <ctime>
#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include <assert.h>   

using std::cout; using std::endl;
using namespace lab2;

int main()
{

	cout <<"--- Testing add_month() -= ---" << endl;
	{
		Gregorian g(1900,10,10);
		Julian j(2001,10,10);
		for(int i = 0; i < 12; i++)
		{
			j.add_month(); g.add_month();
		}
		assert (j.month() == 10); assert (g.month() == 10);
		assert (j.year() == 2002); assert (g.year() == 1901);
	}

	cout <<"--- Testing add_year() -= ---" << endl;
	{
		Gregorian g(2140,8,9); Julian j(2140,8,9);
		j.add_year(18); g.add_year(18);
		assert (j.year() == 2158); assert (g.year() == 2158);
		j.add_year(-18); g.add_year(-18);
		assert (j.year() == 2140); assert (g.year() == 2140);
	}

	cout <<"--- Testing add_month(+-int) -= ---" << endl;
	{
		Gregorian g(1900,10,10);
		Julian j(2001,10,10);
		j.add_month(18); g.add_month(18);
		// cout << "j year: " << j.year() << " month: " << j.month()  << " day " << j.day()<< endl;
		// cout << "g year: " << g.year() << " month: " << g.month()  << " day " << j.day() << endl;
		assert (j.month() == 4); assert (g.month() == 4);
		assert (j.year() == 2003); assert (g.year() == 1902);
		j.add_month(-18); g.add_month(-18);
		// cout << "j year: " << j.year() << " month: " << j.month()  << " day " << j.day()<< endl;
		// cout << "g year: " << g.year() << " month: " << g.month()  << " day " << j.day() << endl;
		assert (j.month() == 10); assert (g.month() == 10);
		assert (j.year() == 2001); assert (g.year() == 1900);

		Gregorian g2(2290,6,6);
		Julian j2(2290,6,6);
		j2.add_month(18); g2.add_month(18);
		// cout << "j2 year: " << j2.year() << " month: " << j2.month()  << " day " << j2.day()<< endl;
		// cout << "g2 year: " << g2.year() << " month: " << g2.month()  << " day " << j2.day() << endl;
		assert (j2.month() == 12); assert (g2.month() == 12);
		assert (j2.year() == 2291); assert (g2.year() == 2291);
		// j2.add_month(18); g2.add_month(18);
		// assert (j.month() == 12); assert (g.month() == 12);
		// assert (j.year() == 2310); assert (g.year() == 2310);

	}
	cout <<"--- Assignment operator =  -= ---" << endl;
	{
		Gregorian g1(1900,10,10); Gregorian g2(2111,1,1);
		Julian j1(2001,10,10); Julian j2(2011,1,1);
		// g1 = g2;
		j1 = j2;
		cout << "g1 year: "<< g1.year() << endl;
		cout << "g2 year: "<< g2.year() << endl;
		cout << "j1 year: "<< j1.year() << endl;
		cout << "j2 year: "<< j2.year() << endl;
		assert(g1.year() == 2111); assert(g1.month() == 1); assert(g1.day() == 1);
		assert(j1.year() == 2010); assert(g1.month() == 1); assert(g1.day() == 1);

	}



	cout << "ALL TESTS COMPLETED" << endl;

	return 0;
}