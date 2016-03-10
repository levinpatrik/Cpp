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

// SCENE
#include "Room.hpp"
#include "Cave.hpp"
#include "Jungle.hpp"
#include "Beach.hpp"



void build_world(std::vector<Scene*>& test){
	Scene* middle_square = new Jungle("You wake up");
	Scene* left_square = new Beach("Maybe take a dip in the ocean");
	Scene* right_square= new Room("Atleast there is a roof over your head");
	Scene* upper_square= new Cave("You try to ignore all the eyes that are watching");
	Scene* lower_square= new Jungle("You prefer the other part of the Jungle");

	middle_square->alter_connections('w', *left_square);
	middle_square->alter_connections('n', *upper_square);
	middle_square->alter_connections('e', *right_square);
	middle_square->alter_connections('s', *lower_square);

   	test.push_back(middle_square);
   	test.push_back(right_square);
   	test.push_back(left_square);
   	test.push_back(upper_square);
   	test.push_back(lower_square);
}



using namespace std;
int main(){
	


	///////////////////////////////////////////////////
	// Fixing connections
	///////////////////////////////////////////////////ui
	std::cout << "------ Building map ------" << std::endl;
	std::vector<Scene*> v;
	build_world(v);
	std::cout << "--- The map is built ---" << std::endl;


	////////////////////////////////////////////////////

	//Running some tests
	std::cout << v[0]->description() << std::endl;
	std::cout << v[0]->get_connections('w').description() << std::endl;	
	std::cout << v[0]->get_connections('e').description() << std::endl;	
	std::cout << v[0]->get_connections('n').description() << std::endl;
	std::cout << v[0]->get_connections('s').description() << std::endl;

	Scene west = v[0]->get_connections('w');
	Scene east = v[0]->get_connections('e');
	Scene north = v[0]->get_connections('n');
	Scene south = v[0]->get_connections('s');


	std::cout << west.get_connections('e').description() << std::endl;
	std::cout << east.get_connections('w').description() << std::endl;
	std::cout << north.get_connections('s').description() << std::endl;
	std::cout << south.get_connections('n').description() << std::endl;
	for(auto element: v){
		delete element;
	}


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
		w.foo();
		// w.hej();

		Item * w_p = &w;

		// w_p->hej();
		// w_p->foo();


		cout << "price weapon sword w_p " << w_p->price() << endl;



	}




	cout << "ALL TEST ARE DONE!" << endl;




	return 0;
}