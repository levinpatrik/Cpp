#include <ctime>
#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include <assert.h>   

using std::cout; using std::endl;
using namespace lab2;

int main()
{
	time_t mytime = time(0);
    set_k_time(mytime);
    



	cout <<"--- Testing add_month() -= ---" << endl;
	{
		Gregorian g(1900,10,10);
		Julian j(2001,10,10);
		cout << g << endl;
		cout << j << endl;
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
		assert (j.month() == 4); assert (g.month() == 4);
		assert (j.year() == 2003); assert (g.year() == 1902);
		j.add_month(-18); g.add_month(-18);
		assert (j.month() == 10); assert (g.month() == 10);
		assert (j.year() == 2001); assert (g.year() == 1900);

		Gregorian g2(2290,6,6);
		Julian j2(2290,6,6);
		j2.add_month(18); g2.add_month(18);
		assert (j2.month() == 12); assert (g2.month() == 12);
		assert (j2.year() == 2291); assert (g2.year() == 2291);


	}
	cout <<"--- Assignment operator =  -= SAME ---" << endl;
	{
		Gregorian g1(1900,10,10); Gregorian g2(2111,1,1);
		Julian j1(2001,10,10); Julian j2(2011,1,1);
		g1 = g2;
		j1 = j2;
		cout << "g1 year: "<< g1.year() << endl;
		cout << "g1 month: "<< g1.month() << endl;
		cout << "g1 day: "<< g1.day() << endl;
		cout << "j1 year: "<< j1.year() << endl;
		cout << "j1 month: "<< j1.month() << endl;
		cout << "j1 day: "<< j1.day() << endl;
		assert(g1.year() == 2111); assert(g1.month() == 1); assert(g1.day() == 1);
		assert(j1.year() == 2011); assert(j1.month() == 1); assert(j1.day() == 1);

	}
	cout <<"--- Assignment operator =  -= DIFFERENT ---" << endl;
	{
		Gregorian g(2000,10,10); Julian j(2010,1,1); Julian j2(1900,5,5); 
		Gregorian g_t;
		// cout <<"g_t today "<< g_t << endl;
		// cout <<"j "<<  j << endl;
		j = g_t;
		// cout <<"g_t today "<< g_t << endl;
		// cout <<"j "<<  j << endl;
		j = g;
		// cout <<"j = g"<<  j << endl;
		cout << j << endl;
		// cout << "J " << j << endl;
		// cout << "G " << g << endl;
		assert(j.year() == 2000); assert(j.month() == 9); assert(j.day() == 27);
		g = j2;
		assert(g.year() == 1900); assert(g.month() == 5); assert(g.day() == 18);		
	}

	cout <<"--- Assignment operator =  -= DIFFERENT ---" << endl;
	{
		Gregorian g(2134,10,10);
	}






	cout << "ALL TESTS COMPLETED" << endl;

	return 0;
}