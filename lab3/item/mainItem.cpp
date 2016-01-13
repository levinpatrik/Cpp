#include "Container.hpp"
#include "Weapon.hpp"
#include "Money.hpp"
#include <iostream>
#include <assert.h>   


using namespace std;
int main()
{

	cout << "SOME NEW TEXT" << endl;
	cout << "---Testing Money()		---" << endl;
	{
		Money m;
		assert (m.price() == 1); 
		assert (m.weight() == 1);
		assert (m.description() == "Money, total amount: 1");

	}

		cout << "---Testing Money(int amount)		---" << endl;
	{
		Money m(10);
		assert (m.price() == 10); 
		assert (m.weight() == 10);
		assert (m.description() == "Money, total amount: 10");

	}

	cout << "---Testing Weapon(int weight, int price, int atk,  std::string description)		---" << endl;
	{
		Weapon w(5,20,2,"Super sword");
		assert(w.weight() == 5);
		assert(w.price() == 20);
		cout << w.description() << endl;

	}

	cout << "---Testing Container(int capacity, int weight, int price, std::string container_description);" << endl;
	{

		Container c(5,0,0,"usefull bag to put items in.");
		assert(c.weight() == 0);
		assert(c.price() == 0);
		cout << c.description() << endl;

	}







	cout << "ALL TESTS COMPLETED " << endl;
	return 0;
}