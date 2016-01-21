#include <iostream>
#include <vector>
#include <string>

//	CHARACTERS
// #include "Animal.hpp"
	#include "Crab.hpp"
	#include "Ape.hpp"
// #include "Character.hpp"
	// #include "Human.hpp"
		#include "Merchant.hpp"
		#include "Pirate.hpp"
		#include "Player.hpp"

//	ITEM
// #include "Item.hpp"
	#include "Container.hpp"
	#include "Money.hpp"
	#include "Weapon.hpp"




using namespace std;
int main(){
	

	cout << "	---		Character std::vector<Character> v;	---" << endl;
	{
		// Ape a; Character * a_p = &a;
		// Crab c; Character * c_p = &c;
		Pirate boss; 
		Character * boss_p = &boss;
		
		Player p; 
		Character * p_p = &p;


		//Add a item to player.
		Weapon w(10, 10 ,10 ,"Sword");
		cout << "description weapon sword w " << w.description() << endl;
		// w.foo();
		// w.hej();



		Item * w_p = &w;
		// w_p->hej();
		// w_p->foo();


		cout << "description weapon sword w_p" << w_p->price() << endl;



	}




	cout << "ALL TEST ARE DONE!" << endl;




	return 0;
}