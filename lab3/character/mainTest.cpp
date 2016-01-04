#include "Crab.hpp"
#include "Ape.hpp"
#include "Merchant.hpp"
#include "Pirate.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;
int main(){

	cout << "	---		Testing Crab		---" << endl;
	{
		Crab c;
		cout <<  "action() " << endl;
		c.action();
		cout << "name() " << endl;
		cout << c.name() << endl;
		cout << "type() " << endl;
		cout << c.type() << endl;
		cout << "(direction) " << endl;
		c.move("West");
	}

	cout << "	---		Testing Ape		---" << endl;
	{
		Ape c;
		cout <<  "action() " << endl;
		c.action();
		cout << "name() " << endl;
		cout << c.name() << endl;
		cout << "type() " << endl;
		cout << c.type() << endl;
		cout << "move(direction) " << endl;
		c.move("West");
	}

	cout << "	---		Testing Merchant	---" << endl;
	{
		Merchant c;
		cout <<  "action() " << endl;
		c.action();
		cout << "name() " << endl;
		cout << c.name() << endl;
		cout << "type() " << endl;
		cout << c.type() << endl;
		cout << "move(direction) " << endl;
		c.move("West");
		cout << "talk() " << endl;
		cout << c.talk("Hello") << endl;
	}

	cout << "	---		Testing Pirate	---" << endl;
	{
		Pirate c;
		cout <<  "action() " << endl;
		c.action();
		cout << "name() " << endl;
		cout << c.name() << endl;
		cout << "type() " << endl;
		cout << c.type() << endl;
		cout << "move(direction) " << endl;
		c.move("West");
		cout << "talk() " << endl;
		cout << c.talk("Hello") << endl;
	}

	cout << "	---		Testing Player	---" << endl;
	{
		Player c;
		cout <<  "action() " << endl;
		c.action();
		cout << "name() " << endl;
		cout << c.name() << endl;
		cout << "type() " << endl;
		cout << c.type() << endl;
		cout << "move(direction) " << endl;
		c.move("West");
		cout << "talk() " << endl;
		cout << c.talk("Hello") << endl;
		cout << "move" << endl;
		c.move("move there");

	}


	return 0;
}