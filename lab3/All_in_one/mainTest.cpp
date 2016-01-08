#include <iostream>
#include <vector>

//	CHARACTERS
#include "Crab.hpp"
#include "Ape.hpp"
#include "Merchant.hpp"
#include "Pirate.hpp"
#include "Player.hpp"

//	ITEM
#include "Container.hpp"
#include "Money.hpp"
#include "Weapon.hpp"




using namespace std;
int main(){

	// cout << "	---		Testing Crab		---" << endl;
	// {
	// 	Crab c;
	// 	cout <<  "action() " << endl;
	// 	c.action();
	// 	cout << "name() " << endl;
	// 	cout << c.name() << endl;
	// 	cout << "type() " << endl;
	// 	cout << c.type() << endl;
	// 	cout << "(direction) " << endl;
	// 	c.move("West");
	// }

	// cout << "	---		Testing Ape		---" << endl;
	// {
	// 	Ape c;
	// 	cout <<  "action() " << endl;
	// 	c.action();
	// 	cout << "name() " << endl;
	// 	cout << c.name() << endl;
	// 	cout << "type() " << endl;
	// 	cout << c.type() << endl;
	// 	cout << "move(direction) " << endl;
	// 	c.move("West");
	// }

	// cout << "	---		Testing Merchant	---" << endl;
	// {
	// 	Merchant c;
	// 	cout <<  "action() " << endl;
	// 	c.action();
	// 	cout << "name() " << endl;
	// 	cout << c.name() << endl;
	// 	cout << "type() " << endl;
	// 	cout << c.type() << endl;
	// 	cout << "move(direction) " << endl;
	// 	c.move("West");
	// 	cout << "talk() " << endl;
	// 	cout << c.talk("Hello") << endl;
	// }

	// cout << "	---		Testing Pirate	---" << endl;
	// {
	// 	Pirate c;
	// 	cout <<  "action() " << endl;
	// 	c.action();
	// 	cout << "name() " << endl;
	// 	cout << c.name() << endl;
	// 	cout << "type() " << endl;
	// 	cout << c.type() << endl;
	// 	cout << "move(direction) " << endl;
	// 	c.move("West");
	// 	cout << "talk() " << endl;
	// 	cout << c.talk("Hello") << endl;
	// }

	// cout << "	---		Testing Player	---" << endl;
	// {
	// 	Player c;
	// 	cout <<  "action() " << endl;
	// 	c.action();
	// 	cout << "name() " << endl;
	// 	cout << c.name() << endl;
	// 	cout << "type() " << endl;
	// 	cout << c.type() << endl;
	// 	cout << "move(direction) " << endl;
	// 	c.move("West");
	// 	cout << "talk() " << endl;
	// 	cout << c.talk("Hello") << endl;
	// 	cout << "move" << endl;
	// 	c.move("move there");

	// }

	cout << "	---		Character std::vector<Character> v;	---" << endl;
	{
		Ape a; Character * a_p = &a;
		Crab c; Character * c_p = &c;
		Pirate boss; Character * boss_p = &boss;
		Player p; Character * p_p = &p;

		std::vector<Character *> v;
		v.push_back(p_p);
		v.push_back(boss_p);

		// //add a item to pirate.
		Weapon w(10, 10 ,10 ,"Sword");
		cout << w.description() << endl;

		v.pop_back();
		v.pop_back();
		

		// Item & w_r = w;
		// v[1]->add(w_r);

		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
	}




	cout << "ALL TEST ARE DONE!" << endl;




	return 0;
}