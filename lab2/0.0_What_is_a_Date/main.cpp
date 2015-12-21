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
		cout << "j year: " << j.year() << " month: " << j.month()  << " day " << j.day()<< endl;
		cout << "g year: " << g.year() << " month: " << g.month()  << " day " << j.day() << endl;
		assert (j.month() == 4); assert (g.month() == 4);
		assert (j.year() == 2003); assert (g.year() == 1902);
		j.add_month(-18); g.add_month(-18);
		cout << "j year: " << j.year() << " month: " << j.month()  << " day " << j.day()<< endl;
		cout << "g year: " << g.year() << " month: " << g.month()  << " day " << j.day() << endl;
		assert (j.month() == 10); assert (g.month() == 10);
		assert (j.year() == 2001); assert (g.year() == 1900);

		Gregorian g2(2290,6,6);
		Julian j2(2290,6,6);
		j2.add_month(18); g2.add_month(18);
		cout << "j2 year: " << j2.year() << " month: " << j2.month()  << " day " << j2.day()<< endl;
		cout << "g2 year: " << g2.year() << " month: " << g2.month()  << " day " << j2.day() << endl;
		assert (j2.month() == 12); assert (g2.month() == 12);
		assert (j2.year() == 2291); assert (g2.year() == 2291);
		// j2.add_month(18); g2.add_month(18);
		// assert (j.month() == 12); assert (g.month() == 12);
		// assert (j.year() == 2310); assert (g.year() == 2310);

	}


	// time_t mytime = time(0);
	// set_k_time(mytime);
	// std::cout << "Inside main:" << std::endl;

	// cout <<"--- Testing constructor Julian -= ---" << endl;
	// {
	// 	cout << "(year,month,day)" << endl;
	// 	Julian j1(2020,10,10); Julian j2(2015,10,10); 
	// 	cout << "COPY" << endl;
	// 	Julian jcopy(j1);
	// 	cout << "Default" << endl;
	// 	Julian jdefualt;
	// }

	// Julian j;
	// cout << j << endl;
	// Gregorian g;
	// cout << g << endl;

	// int diff33 = g - j;
	// cout << diff33 << endl;

 // 	{
	// Gregorian g;
	// cout << "week_day: " << g.week_day() << "week_day_name" << g.week_day_name() << endl;
	// for(int i = 0; i < 15; i ++)
	// {
	// 	cout << "Day: " << g.week_day_name() << " i" << i << endl;
	// 	g++;
	// }
	// }



	// cout <<"--- Testing g -= ---" << endl;
	// {
	// Gregorian g(2010,10,10);
	// for(int i = 0; i < 3; i ++){
	// 	g -= 100;
	// }
	// }

	// cout <<"--- Testing j1-j2 -= ---" << endl;
	// {
	// Julian j1(2000,1,1);
	// Julian j2(2000,2,1);
	// int diff1 = j2-j1;
	// int diff2 = j1 -j2;
	// cout << "Diff+ = " << diff1 << endl;
	// cout << "Diff- = " << diff2 << endl;
	// }

	// cout <<"--- Testing g1-g2 -= ---" << endl;
	// {
	// Gregorian j1(2000,2,10);
	// Gregorian j2(2000,3,10);
	// int diff1 = j2-j1;
	// int diff2 = j1 -j2;
	// cout << "Diff+ = " << diff1 << endl;
	// cout << "Diff- = " << diff2 << endl;
	// }

	// cout <<"--- Testing j - g -= ---" << endl;
	// {
	// Gregorian g1(1900,1,1); Gregorian g2(1900,1,13);
	// Julian j1(1899,12,20); Julian j2(1900,1,1);
	// int diff1 = g1-j1;
	// int diff2 = g2 -j2;
	// cout << "Diff+ = " << diff1 << endl;
	// cout << "Diff- = " << diff2 << endl;
	// }

	
	// cout <<"--- Testing MJDN -= ---" << endl;
	// {
	// 	Gregorian g1(1858,11,16); Gregorian g2(1858,11,17); Gregorian g3(1858,11,18);
	// 	Julian j1(1858,11,4); Julian j2(1858,11,5); Julian j3(1858,11,6);
	// 	cout << " JDN should be -1,0,1 " << g1.mod_julian_day() << g2.mod_julian_day() << g3.mod_julian_day() << endl;
	// 	cout << " JDN should be -1,0,1 " << j1.mod_julian_day() << j2.mod_julian_day() << j3.mod_julian_day() << endl;
	// }


	// cout <<"--- Testing  << ---" << endl;
	// {
	// 	Gregorian g(2001,10,10); Julian j(2010,1,1);
	// 	cout << "should be 2001,10,10 " << g << endl;
	// 	cout << "should be 2010,1,1 " << j << endl;


	// }



	// Gregorian g1(2001,3,24);
	// Julian j1(2012,10,1);

	// cout << j1.year() << endl;
	// cout << j1.month() << endl;
	// cout << j1.day() << endl;

	// cout << g1.year() << endl;
	// cout << g1.month() << endl;
	// cout << g1.day() << endl;

	// cout << g1.week_day_name() << endl;
	// cout << g1.month_name() << endl;

	// j1+=3; g+=3;

	// --j1; --g;
	// j1++; j1--;
	// g++; g--;

	// Julian j2(2012,10,10); Julian j3(2011,10,1);
	// int diff = j2-j3;
	// cout << "j - j:	diff is " << diff << endl;

	// Gregorian g2(2012,10,10); Gregorian g3(2011,10,1);
	// diff = g2-g3;
	// cout << "g - g:	diff is " << diff << endl;



	// Gregorian g4(2012,10,10); Julian j4(2011,10,1);
	// diff = g4 - j4;
	// cout << "g - j:	diff is " << diff << endl;

	// Gregorian g5(2012,10,10); Julian j5(2011,10,1);
	// diff = j5 - g5;
	// cout << "j - g:	diff is " << diff << endl;

	// Gregorian g6(2010,10,10);
	// cout << g6.julian_day_number() << endl;

	// Julian j6(2010,10,10);
	// cout << j6.julian_day_number() << endl;

	// cout <<" 2010,10,10 G -> J  [year,month,day] " << 
	// g6.JDN_2_julian(g6.julian_day_number())[0] << "," <<  
	// g6.JDN_2_julian(g6.julian_day_number())[1] << ","  << 
	// g6.JDN_2_julian(g6.julian_day_number())[2] << endl;

	// cout << "J -> G  [year,month,day] " << 
	// g6.JDN_2_Greg(g6.julian_day_number())[0] << "," <<  
	// g6.JDN_2_Greg(g6.julian_day_number())[1] << ","  << 
	// g6.JDN_2_Greg(g6.julian_day_number())[2] << endl;

	// bool b = (g6 == j6);

	// Julian j7(2010,9,27);
	// bool b2 = (j7 == g6);

	// cout << "Should be 0: " << b << endl;
	// cout << "Should be 1: " << b2 << endl;



	// cout << j7 << endl;

	// Julian j9;
	// cout <<"j9 " << (j9 =g6) << endl; 

	// j9.add_year(1);
	// cout <<"j9 +1 year " << j9 << endl; 

	// Julian j10(2000,1,1);
	// j10.add_month(500);
	// cout <<"j10 +500 month " << j10 << endl;


	// //test defualt constructor
	// {
	// 	cout << "--- Default constructor test ---" << endl;
	// 	Gregorian g;
	// 	Julian j;
	// 	cout << "Julian date" << j << "Gregorian date " << g << endl;

	// }



	// //	test = operator
	// {
	// 	Gregorian y(2006,8,1);
	// 	Julian x;
	// 	x = y;
	// 	cout << x << endl;
	// }

	// // test on = on pointer to base class
	// {

	// 	Date * p1 = new Julian ();
	// 	Date * p2 = new Gregorian (1900, 1, 1);
	// 	*p1 = *p2; 
	// 	cout << "*p1= " << *p1<< endl; // 1899-12-20
	// 	delete p2; delete p1;
	// }


	return 0;
}