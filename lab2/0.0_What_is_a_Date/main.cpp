#include <ctime>
#include "Date.h"
#include "Gregorian.h"
#include "Julian.h"
using namespace std;

int main()
{
	std::cout << "Inside main:" << std::endl;
	Gregorian g;
	Gregorian g1(2001,3,24);
	Julian j;
	Julian j1(2012,10,1);

	cout << j1.year() << endl;
	cout << j1.month() << endl;
	cout << j1.day() << endl;

	cout << g1.year() << endl;
	cout << g1.month() << endl;
	cout << g1.day() << endl;

	cout << g1.week_day_name() << endl;
	cout << g1.month_name() << endl;

	cout << j1.is_leap_year() << endl;
	cout << g1.is_leap_year() << endl;

	j1+=3; g+=3;

	--j1; --g;
	j1++; j1--;
	g++; g--;

	Julian j2(2012,10,10); Julian j3(2011,10,1);
	int diff = j2-j3;
	cout << "j - j:	diff is " << diff << endl;

	Gregorian g2(2012,10,10); Gregorian g3(2011,10,1);
	diff = g2-g3;
	cout << "g - g:	diff is " << diff << endl;



	Gregorian g4(2012,10,10); Julian j4(2011,10,1);
	diff = g4 - j4;
	cout << "g - j:	diff is " << diff << endl;

	Gregorian g5(2012,10,10); Julian j5(2011,10,1);
	diff = j5 - g5;
	cout << "j - g:	diff is " << diff << endl;



	Gregorian g6(2010,10,10);
	cout << g6.julian_day_number() << endl;

	Julian j6(2010,10,10);
	cout << j6.julian_day_number() << endl;

	cout <<" 2010,10,10 G -> J  [year,month,day] " << 
	g6.JDN_2_julian(g6.julian_day_number())[0] << "," <<  
	g6.JDN_2_julian(g6.julian_day_number())[1] << ","  << 
	g6.JDN_2_julian(g6.julian_day_number())[2] << endl;

	cout << "J -> G  [year,month,day] " << 
	g6.JDN_2_Greg(g6.julian_day_number())[0] << "," <<  
	g6.JDN_2_Greg(g6.julian_day_number())[1] << ","  << 
	g6.JDN_2_Greg(g6.julian_day_number())[2] << endl;

	bool b = (g6 == j6);

	Julian j7(2010,9,27);
	bool b2 = (j7 == g6);

	cout << "Should be 0: " << b << endl;
	cout << "Should be 1: " << b2 << endl;

	cout << j7 << endl;

	Julian j9;
	cout <<"j9 " << (j9 =g6) << endl; 

	j9.add_year(1);
	cout <<"j9 +1 year " << j9 << endl; 

	Julian j10(2000,1,1);
	j10.add_month(500);
	cout <<"j10 +500 month " << j10 << endl; 





	return 0;
}