#include <iostream>
#include <vector>
#include <string>

//	CHARACTERS
#include "Animal.hpp"
	#include "Crab.hpp"
	#include "Ape.hpp"
#include "Character.hpp"
	#include "Human.hpp"
		#include "Merchant.hpp"
		#include "Pirate.hpp"
		#include "Player.hpp"

//	ITEM
#include "Item.hpp"
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
		// Ape a; Character * a_p = &a;
		// Crab c; Character * c_p = &c;
		Pirate boss; Character * boss_p = &boss;
		Player p; Character * p_p = &p;

		std::vector<Character *> v;
		v.push_back(p_p);
		std::cout << v[0]->description() << std::endl;
		v.pop_back();
		v.push_back(boss_p);
		std::cout << v[0]->description() << std::endl;
		v.pop_back();

		//Add a item to player.
		// Weapon w(10, 10 ,10 ,"Sword");
		// cout << w.description() << endl;


		Weapon * w_p = new Weapon(10, 10 ,10 ,"Sword");
		// Item * i_p = w_p;

		// std::cout << i_p->description() << std::endl;
		// v.push_back(p_p);
		// v[0]->add(i_p);

		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
		// v[0]->attack(*(v[1]));
	}




	cout << "ALL TEST ARE DONE!" << endl;




	return 0;
}