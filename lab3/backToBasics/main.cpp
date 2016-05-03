#include "player.hpp"
#include "scene.hpp"
#include "item.hpp"

#include <iostream>
#include <assert.h>
#include <string> 
#include <sstream>

#include <unistd.h>

using namespace std;
using namespace game;

void gameOver();

class GameItem
{

public:
		virtual void virtFunc(std::string s)
		{
			std::cout << "Base class func! " << std::endl;
		}
protected:
	int i;
};

class Test
{

public:
void f1(std::string s) const
{
	cout << "Test::f1"  << s << endl;
}
void f2(std::string s) const
{
	cout << "Test::f2"  << s << endl;
}
// void f3(std::string s) const
// {
// 	cout << "Test::f3" << s << endl;
// }


};



class Bar : public GameItem
{
public:
	void foo1(std::string s)
	{ 
		cout << "Bar::foo1 "  << s << endl;
	}
	void foo2(std::string s)
	{
		cout << "Bar::foo2 "  << s << endl;
	}

virtual void virtFunc(std::string s)
{
	cout << "virtual function TEST " << s <<  endl;

}
};


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}



int main()
{
	cout << "MAIN" << endl;
	
	// cout << "------	Read input TESTS ------" << endl;
	// {
	//     std::string input;
	//     //getline( std::cin, input );
	// 	std::vector<std::string> input_vec;
	// 	char delim = ' ';
	// 	input_vec = split(input, delim);
	// 	for(int i = 0; i < input_vec.size(); i++)
	// 	{
	// 		cout << input_vec[i] << endl;
	// 	}

	// }
	// cout << "------	ITEM TESTS ------" << endl;
	// {
	// 	Item i1;
	// 	Item i2("its shiny", "sword", 10);
	// 	assert (i1.getDescription() == "-");
	// 	assert (i1.getPrice() == 0);
	// 	assert (i1.getName() == "-");

	// 	assert (i2.getDescription() == "its shiny");
	// 	assert (i2.getPrice() == 10);
	// 	assert (i2.getName() == "sword");
	// }

	// cout << "------	PLAYER TESTS ------" << endl;
	// {
	// 	// ---- getName -----
	// 	Player c1;
	// 	assert( c1.getName() == "-");
	// 	Player c2("another name", 10, 10);
	// 	assert( c2.getName() == "another name");

	// 	// ---- getAtk -----
	// 	assert( c1.getAtk() == 0);	
	// 	assert( c2.getAtk() == 10);	

	// 	// ---- setAtk -----
	// 	c1.setAtk(5);
	// 	c2.setAtk(6);
	// 	assert( c1.getAtk() == 5);	
	// 	assert( c2.getAtk() == 6);

	// 	// ---- getHp -----
	// 	assert( c1.getHp() == 0);	
	// 	assert( c2.getHp() == 10);	

	// 	// ---- setHp -----
	// 	c1.setHp(5);
	// 	c2.setHp(6);
	// 	assert( c1.getHp() == 5);	
	// 	assert( c2.getHp() == 6);

	// 	// ---- setItem / removeItem -----
	// 	Item i1("a green shield", "shield", 10);
	// 	Item i2("a red sword", "sword", 10);
	// 	Item i3("a blue Helmet", "helmet", 1);
	// 	Item i4;
	// 	Item * tmp = &i4;
	// 	tmp = c1.removeItem("adabdad");
	// 	c1.setItem(&i1);
	// 	c1.setItem(&i2);
	// 	c1.setItem(&i3);
	// 	c1.setItem(&i4);
	// 	c1.removeItem("shield");
	// 	c1.removeItem("sword");
	// 	tmp = c1.removeItem("helmet");
	// 	tmp = c1.removeItem("-");	
	// }

	// cout << "------	SCENE TESTS ------" << endl;
	// {

	// 	//---  PRINTS  ---
	// 	Scene s1("Another place");
	// 	Scene s2("A beach");
	// 	Scene s3("A beach2");

	// 	Item i1;
	// 	Item i2("its shiny", "sword", 10);

	// 	//---  SETTERS  ---
	// 	s1.setItem(&i1);
	// 	s1.setItem(&i2);
	// 	s1.printItems();
		
	// 	Item * i_p = &i1;
	// 	i_p = s1.removeItem("sword");
	// 	assert(&i2 == i_p);
	// 	i_p = s1.removeItem("-");
	// 	assert(&i1 == i_p);
	// 	s1.printItems();

	// 	Player p1("Monster1",10,10);
	// 	Player p2("Monster2",10,10);
	// 	Player p3("Player",10,10);		

	// 	s1.setPlayer(&p1);
	// 	s1.setPlayer(&p2);
	// 	s1.setPlayer(&p3);
	// 	s1.printPlayers();
	// 	s1.removePlayer("Monster1");
	// 	s1.removePlayer("Monster2");
	// 	s1.removePlayer("Player");
	// 	s1.printPlayers();


	// 	s1.printExits();
	// 	s1.setExit("e", &s2);
	// 	s1.setExit("w", &s2);
	// 	s1.setExit("s", &s3);
	// 	s1.setExit("n", &s3);
	// 	s1.printExits();

	// 	Scene * s_p;
	// 	s_p = s1.removeExit("e");
	// 	s_p = s1.removeExit("w");
	// 	s_p = s1.removeExit("n");
	// 	s_p = s1.removeExit("s");
	// 	s1.printExits();
	// }

	// cout << "------	MAP test ------	" << endl;
	// {
	// 	Test T;
	// 	Bar B;
	// 	GameItem * G_p = &B;


	// 	// game_fp func_p = &GameItem::virtFunc;
	// 	// (G_p->*func_p)("en string");
		


	// 	typedef void (Test::*test_fp)(std::string) const;
	// 	typedef void (Bar::*bar_fp)(std::string);
	// 	typedef void (GameItem::*game_fp)(std::string);

	// 	//Function ptr maps
 //  		std::map <std::string, test_fp> testFunc_map;
 //  		std::map <std::string, bar_fp> barFunc_map;
 //  		std::map <std::string, game_fp> gameFunc_map;


 //  		//Object ptr maps
 //  		std::map<std::string, Test *> testObj_map;
 //  		std::map<std::string, Bar *> barObj_map;
 //  		std::map<std::string, GameItem *> gameObj_map;

	// 	testFunc_map.insert(std::make_pair("f1", &Test::f1));
 //  		testFunc_map.insert(std::make_pair("f2", &Test::f2));
 //  		// testFunc_map.insert(std::make_pair("f3", &Test::f3));

	// 	barFunc_map.insert(std::make_pair("foo1", &Bar::foo1));
	// 	barFunc_map.insert(std::make_pair("foo2", &Bar::foo2));

	// 	testObj_map.insert(std::make_pair("t", &T));
	// 	barObj_map.insert(std::make_pair("b", &B));

	// 	gameFunc_map.insert(std::make_pair("virt", &GameItem::virtFunc));
	// 	gameObj_map.insert(std::make_pair("game", G_p));

	// 	// std::cout <<"call fun: " << endl;
	// 	std::string a;
	// 	// std::cout <<"on obj: " << endl;
	// 	std::string b;
			
	// 	while(a != "x")
	// 	{
	// 		std::cout <<"call fun: " << endl;
	// 		cin >> a;
	// 		std::cout <<"on obj: " << endl;
	// 		cin >> b;

	// 		auto it_1 = barFunc_map.find(a);
	// 		auto it_2 = testFunc_map.find(a);
	// 		auto it_6 = gameFunc_map.find(a);
	// 		auto it_3 = testObj_map.find(b);
	// 		auto it_4 = barObj_map.find(b);
	// 		auto it_5 = gameObj_map.find(b);

	// 		if(it_1 != barFunc_map.end() && it_4 != barObj_map.end() )
	// 		{
	// 			auto barFunc_p = it_1->second;
	// 			auto barObj_p = it_4->second;
	// 			(barObj_p->*barFunc_p)("BAR!");
	// 		}
	// 		else if(it_2 != testFunc_map.end() && it_3 != testObj_map.end())
	// 		{
	// 			auto testFunc_p = it_2->second;
	// 			auto testObj_p = it_3->second;
	// 			(testObj_p->*testFunc_p)("TEST!");
	// 		}
	// 		else if(it_5 != gameObj_map.end() && it_6 != gameFunc_map.end())
	// 		{

	// 			auto gameobj_p = it_5->second;
	// 			auto gamefunc_p = it_6->second;
	// 			(gameobj_p->*gamefunc_p)("TEST!");

	// 		}
	// 		else
	// 		{
	// 			std::cout << "You can not do that. " << std::endl;
	// 		}			


	// 			// auto test_fptr = it_2->second;
	// 			// (T.*test_fptr)("Hej");
	// 	}
	// }



	cout << "------	REAL GAME TEST ------	" << endl;
	{

		//---  CONSTRUCT ALL OBJECTS ---
		Scene s1("Starting zone");
		Scene s2("artic tundra");
		Scene s3("A beach");

		Item i1;
		Item i2("It looks rusty", "sword", 10, 3 , 1);
		Item i3("Its a crappy hat", "hat", 2, 0, 2);
	

		//---  BUILD THE MAP  ---
		s1.setItem(&i2);
		
		Item * i_p = &i1;

		Player p1("monster1",10,1);
		Player p2("monster2",10,1);

		Player p3("lootmonster", 10,1);
		Item i4("test", "crown", 10, 3 , 1);
		p3.setItem(&i4);

		Player main_char("Player",30,10);	
		Player p4("monster3",20,2);
		Player p5("monster4",10,30);			
		s1.setPlayer(&p1);
		s1.setPlayer(&p2);
		s1.setPlayer(&p3);
		s1.setPlayer(&main_char);

		s2.setPlayer(&p4);
		s2.setPlayer(&p5);
		s2.setItem(&i3);

		s1.setExit("east", &s2);
		s1.setExit("west", &s2);
		s1.setExit("south", &s3);
		s1.setExit("north", &s3);


		s2.setExit("east", &s1);
		s2.setExit("west", &s1);
		s2.setExit("south", &s3);
		s2.setExit("north", &s3);


		s3.setExit("east", &s2);
		s3.setExit("west", &s2);
		s3.setExit("south", &s1);
		s3.setExit("north", &s1);


		//--- Insert all function pointers in Player and Scene map --- 
		typedef void (Scene::*scene_funcs)();
		std::map<std::string, scene_funcs> scene_funcMap;
		scene_funcMap.insert(std::make_pair("pickup", &Scene::pickup));
		scene_funcMap.insert(std::make_pair("drop", &Scene::drop));
		scene_funcMap.insert(std::make_pair("fight", &Scene::fight));

		//--- Insert all function pointers in Player and Scene map --- 
		typedef void (Player::*player_funcs)();
		std::map<std::string, player_funcs> player_funcMap;
		player_funcMap.insert(std::make_pair("equip", &Player::equip));
		player_funcMap.insert(std::make_pair("unequip", &Player::unequip));


		std::string a;
		auto current_scene_p = &s1;
		current_scene_p->printDescription();
		current_scene_p->printPlayers();
		current_scene_p->printItems();
		current_scene_p->printExits();
		while(main_char.getHp() > 0)
		{

			cout << "What do you want to do?" << endl;
			cout << "Options: 'go', 'pickup', drop, fight, equip, unequip"  << endl;
			cin >> a;
			auto s_it = scene_funcMap.find(a);
			auto p_it = player_funcMap.find(a);

			if(s_it != scene_funcMap.end())				//function found
			{
				cout << string( 100, '\n' );
				auto s_fp = s_it->second; 				//points at correct function
				(current_scene_p->*s_fp)();  			//execute the function

			}

			else if(p_it != player_funcMap.end())		//function found
			{
				cout << string( 100, '\n' );
				auto p_fp = p_it->second; 				//points at correct function
				(main_char.*p_fp)();					//execute the function
			}

			else if(a.compare("go") == 0)
			{
				cout << string( 100, '\n' );
				current_scene_p = current_scene_p->go();
				cout << string( 100, '\n' );
				current_scene_p->printDescription();
				current_scene_p->printPlayers();
				current_scene_p->printItems();
				current_scene_p->printExits();
			}
			else
			{
				cout << "'"<< a <<"' is not a valid option" << endl;
			}
		}
		gameOver();
	}






	// cout << "------	REAL GAME TEST ------	" << endl;
	// {


	// 	// auto g_1 = gameFunc_map.find("virtFunc");
	// 	// auto g_func = g_1->second;
	// 	// auto g_2  = gameObj_map.find("game");
	// 	// auto g_obj = g_2->second;

	// 	// (g_obj->*g_func)("en string");
	
	// 	///////////////////////////////////////////////
	// 	//börjar göra riktiga implementationer nu
	// 	///////////////////////////////////////////////
	// 	Scene s1("Starting zone");
	// 	Scene s2("artic tundra");
	// 	Scene s3("A beach");

	// 	Item i1;
	// 	Item i2("it is a rusty looking", "sword", 10, 3 , 1);
	// 	Item i3("it is a crappy hat", "hat", 2, 0, 2);

	// 	//---  SETTERS  ---
	// 	// s1.setItem(&i1);
	// 	s1.setItem(&i2);
	// 	// s1.printItems();
		
	// 	Item * i_p = &i1;

	// 	Player p1("Monster1",10,1);
	// 	Player p2("Monster2",10,1);
	// 	Player main_char("Player",30,10);	
	// 	Player p4("moster3",20,2);
	// 	Player p5("moster4",10,30);			
	// 	s1.setPlayer(&p1);
	// 	s1.setPlayer(&p2);
	// 	s1.setPlayer(&main_char);

	// 	s2.setPlayer(&p4);
	// 	s2.setPlayer(&p5);
	// 	s2.setItem(&i3);

	// 	s1.setExit("e", &s2);
	// 	s1.setExit("w", &s2);
	// 	s1.setExit("s", &s3);
	// 	s1.setExit("n", &s3);


	// 	s2.setExit("e", &s1);
	// 	s2.setExit("w", &s1);
	// 	s2.setExit("s", &s3);
	// 	s2.setExit("n", &s3);


	// 	s3.setExit("e", &s2);
	// 	s3.setExit("w", &s2);
	// 	s3.setExit("s", &s1);
	// 	s3.setExit("n", &s1);

	// 	//Creating Function ptr maps
	// 	// typedef void (Scene::*info_fp)() const;
	// 	// std::map <std::string, info_fp> infoFuncs_map;
	// 	// infoFuncs_map.insert(std::make_pair("info", &Scene::printItems));
	// 	// infoFuncs_map.insert(std::make_pair("info", &Scene::printDescription));
	// 	// infoFuncs_map.insert(std::make_pair("info", &Scene::printPlayers));
	// 	// infoFuncs_map.insert(std::make_pair("info",&Scene::printExits));


	// 	// typedef void (Scene::*perform_fp)(std::string);
	// 	// std::map <std::string, perform_fp> actionFuncs_map;
	// 	// actionFuncs_map.insert(std::make_pair("go", &Scene::go));
	// 	// actionFuncs_map.insert(std::make_pair("pickup", &Scene::pickup));
	// 	// actionFuncs_map.insert(std::make_pair("drop", &Scene::drop));

	// 	typedef Scene* (Scene::*move_fp)(std::string);
	// 	std::map <std::string, move_fp> moveFunc_map;
	// 	moveFunc_map.insert(std::make_pair("go", &Scene::getExit));

	// 	typedef Item* (Scene::*pickup_fp)(std::string);
	// 	std::map <std::string, pickup_fp> pickupFunc_map;
	// 	pickupFunc_map.insert(std::make_pair("pickup", &Scene::getItem));

	// 	typedef Player* (Scene::*target_fp)(std::string);
	// 	std::map <std::string, target_fp> targetFunc_map;
	// 	targetFunc_map.insert(std::make_pair("fight", &Scene::getPlayer)); 

	// 	typedef void (Player::*equip_fp)(std::string);
	// 	std::map <std::string, equip_fp> equip_map;
	// 	equip_map.insert(std::make_pair("equip", &Player::equip));
	// 	equip_map.insert(std::make_pair("unequip", &Player::unequip));

	// 	// Player * getPlayer(std::string name);

	// 	// void Player::setItem(Item * i)
	// 	// Item * getItem(std::string item_name)(std::string);
	// 	//Objct ptr maps
	// 	// std::map<std::string, Test *> scene_map;
	// 	// testObj_map.insert(std::make_pair("s1", &s1))


	// 	// Creatin object pointer maps


	// 	//The action loop
	// 	std::string a;
	// 	std::string b;
	// 	Scene* current_scene_p = &s1;
	// 	bool done = false;
	// 	bool zone_change = false;

	// 	cout << "You are currently in ";
	// 	current_scene_p->printDescription();
	// 	current_scene_p->printPlayers();
	// 	current_scene_p->printItems();
	// 	current_scene_p->printExits();
	// 	while(main_char.getHp() > 0)
	// 	{


	// 		cout << "What do you want to do?" << endl;
	// 		cout << "Options: 'go', 'pickup' or 'fight'" << endl;
	// 		cin >> a;
	// 		auto it_1 = moveFunc_map.find(a);
	// 		auto it_2 = pickupFunc_map.find(a);
	// 		auto it_3 = targetFunc_map.find(a);
	// 		auto it_4 = equip_map.find(a);
	// 		std::string exit_str =  "exit";

	// 		//Change Zone
	// 		if(it_1 != moveFunc_map.end())
	// 		{
	// 			done = false;
	// 			zone_change= false;
	// 			cout << string( 100, '\n' );
	// 			while(done == false)
	// 			{
	// 				cout << "which direction would you like to go?" << endl;
	// 				cin >> b;
	// 				auto movingFunc_p = it_1 -> second;
	// 				auto temp_p = current_scene_p;
	// 				current_scene_p = (current_scene_p->*movingFunc_p)(b);
	// 				if(current_scene_p != NULL)
	// 				{
	// 					current_scene_p-> setPlayer(&main_char);
	// 					done = true;
	// 					zone_change = true;
	// 					cout << endl << endl;
	// 					cout << "You are currently in" << endl;
	// 					current_scene_p->printDescription();
	// 					current_scene_p->printPlayers();
	// 					current_scene_p->printItems();
	// 					current_scene_p->printExits();
	// 				}
	// 				else if(b.compare(exit_str) == 0){
	// 					done = true;
	// 					current_scene_p = temp_p;
	// 				}
	// 				else
	// 				{
	// 					cout << "There is no direction called: " << b << endl;
	// 					cout << "Type 'exit' if you wish to go back to your original choices" << endl;
	// 					current_scene_p = temp_p;
	// 				}

	// 			}
	// 		}
	// 		else if(it_2 != pickupFunc_map.end())
	// 		{
	// 			done = false;
	// 			zone_change = false;
	// 			cout << string( 100, '\n' );
	// 			while(done == false)
	// 			{
	// 				cout << "What do you want to pick up?" << endl;
	// 				current_scene_p->printItems();
	// 				cin >> b;
	// 				auto pickupFunc_p = it_2->second;
	// 				auto item_ptr = (current_scene_p->*pickupFunc_p)(b);
	// 				if(item_ptr != NULL) //if item exists
	// 				{
	// 					current_scene_p->removeItem(b); //remove it from scene
	// 					main_char.setItem(item_ptr);    //give item to main char
	// 					cout << "In your inventory" << endl;
	// 					main_char.printInventory();
	// 					done = true;
	// 				}
	// 				else if(b.compare(exit_str) == 0){
	// 					done = true;
	// 				}
	// 				else
	// 				{
	// 					cout << "There is no item with the name: " << b << endl;
	// 					cout << "Type 'exit' if you wish to go back to your original choices" << endl;
	// 				}
	// 			}	

	// 		}
	// 		else if(it_3 != targetFunc_map.end())
	// 		{
	// 			done = false;
	// 			zone_change = false;
	// 			cout << string( 100, '\n' );
	// 			while(done == false)
	// 			{
	// 				cout << "Who do you wish to attack?" << endl;
	// 				current_scene_p->printPlayers();
	// 				cin >> b;
	// 				auto tartgetFunc_p = it_3->second;
	// 				auto target_ptr = (current_scene_p->*tartgetFunc_p)(b);
	// 				if(target_ptr != NULL)
	// 				{
	// 					cout << b << " HP: " <<  target_ptr->getHp() << endl; 
	// 					main_char.attack(target_ptr);
	// 					cout << "You attack!" << endl;
	// 					cout << b << " HP: " <<  target_ptr->getHp() << endl;
	// 					done = true;
	// 					if(target_ptr->getHp() >= 0){
	// 						cout << "You killled " << b << endl;
	// 						current_scene_p->removePlayer(b);
	// 						// cout << "number of players in the zone = ";
	// 						// cout << current_scene_p->getNumberOfPlayers() << endl;
	// 					}
	// 				}
	// 				else if(b.compare(exit_str) == 0)
	// 				{
	// 					done = true;
	// 				}
	// 				else
	// 				{
	// 					cout << "There is no monster with the name: " << b << endl;
	// 					cout << "Type 'exit' if you wish to go back to your original choices" << endl;
	// 					cout << endl << endl;		
	// 				}
	// 			}

	// 		}
	// 		if(b.compare(exit_str) != 0 && zone_change ==false){
	// 			for(int i  = 0; i < (current_scene_p->getNumberOfPlayers()-1); ++i)
	// 			{
	// 				auto monster_p = current_scene_p->action();
	// 				cout << "Your current hp is: " << main_char.getHp() << endl;
	// 				cout << monster_p->getName() <<" attacks you" <<endl;
	// 				monster_p->attack(&main_char);
	// 				cout << "Your current hp is: " << main_char.getHp() << endl;
	// 			}

	// 		}
	// 		//left 2 implement  monsters attacking
	// 		// Scene* curr_scene_ptr = &s1; 

			
	// 		/* ska skriva ut infon när man kommer in i en ny zon
	// 			ska kolla vilken zon man e i
	// 			testa ad som händer om flera funs e kopplade till samma keyword
	// 			testa minings splittaren			
	// 		*/	

	// 	}
	// 	gameOver();




		// if(it_1 != barFunc_map.end() && it_4 != barObj_map.end() )
		// {
		// 	auto barFunc_p = it_1->second;
		// 	auto barObj_p = it_4->second;
		// 	(barObj_p->*barFunc_p)("BAR!");
		// }



		// std::cout <<"on obj: " << endl;

		//(s1.*infoFuncs_map)();		

		// //Objct ptr maps


		// //Function ptr maps
  // 		std::map <std::string, test_fp> testFunc_map;
  // 		std::map <std::string, bar_fp> barFunc_map;
  // 		std::map <std::string, game_fp> gameFunc_map;


  // 		//Object ptr maps
  // 		std::map<std::string, Test *> testObj_map;
  // 		std::map<std::string, Bar *> barObj_map;
  // 		std::map<std::string, GameItem *> gameObj_map;

		// testFunc_map.insert(std::make_pair("f1", &Test::f1));
  // 		testFunc_map.insert(std::make_pair("f2", &Test::f2));

		// barFunc_map.insert(std::make_pair("foo1", &Bar::foo1));
		// barFunc_map.insert(std::make_pair("foo2", &Bar::foo2));

		// testObj_map.insert(std::make_pair("t", &T));
		// barObj_map.insert(std::make_pair("b", &B));

		// gameFunc_map.insert(std::make_pair("virt", &GameItem::virtFunc));
		// gameObj_map.insert(std::make_pair("game", G_p));

	// }
		//typedef void (Scene::*test_sp)(std::string);
		//std::map <std::string, test_p> testScene_map;
		//testFunc_map.insert(std::make_pair("exit", &Test::getExit));
	// 	std::string x;

	// while(1)
	// {
	// 	cin >> x;
	// 	auto it_test = scene_map.find(x);
	// 	// (s1->*info_fp)();

	// }	





	// cout << "------	CIN test ------	" << endl;
	// {
	// 	// cout << "which function do you want to call?" << endl;
	// 	// std::string a;
	// 	// cin >> a;


	// 	Scene s("A desctiption");
	// 	Player p("player", 10, 1);
	// 	Player m("monster", 5, 1);
	// 	Player m2("boss", 50, 1);
	// 	s.setPlayer(&p);
	// 	s.setPlayer(&m);
	// 	s.setPlayer(&m2);

	// 	std::string action_str;
	// 	std::string target_str;
	// 	Player * p_tmp;

	// 	Player * t = NULL;
	// 	typedef void (Player::*MFP)(Player *);
 //   		std::map <std::string, MFP> fmap;
	// 	fmap.insert(std::make_pair("atk", &Player::attack));
	// 	// (t->*f_ptr)();




	// 	while(1)
	// 	{
	// 		auto p_p = s.action();
	// 		if(p_p->getName() == "player")
	// 		{
	// 			cout << "What do you want to do? " << endl;
	// 			cin >> action_str;
	// 			cout << "Who do you want to attack? " << endl;
	// 			cin >> target_str;

	// 			MFP f_ptr = fmap[action_str];
	// 			p_tmp = p_tmp = s.getPlayer(target_str);
	// 			cout << p_tmp->getName() << " HP: " <<  p_tmp->getHp() << endl;
	// 			p_p->attack(p_tmp);
	// 			cout << p_tmp->getName() << " HP: " <<  p_tmp->getHp() << endl;
	// 		}
	// 		else
	// 		{
	// 			p_tmp = s.getPlayer("player");
	// 			cout << p_tmp->getName() << " HP: " <<  p_tmp->getHp() << endl;
	// 			p_p->attack(p_tmp);
	// 			cout << p_tmp->getName() << " HP: " <<  p_tmp->getHp() << endl;
	// 		}
	// 	}

	// }



	return 0;

}




void gameOver()
{

		cout << endl;
		usleep(100000);
		cout << endl;
		cout << "             YOU HAVE DIED!" << endl;
		for(uint i = 0; i < 20 ; i++){
			usleep(100000);
			cout << endl;
		}

		cout << "               GAME OVER! " << endl;
		for(uint i = 0; i < 20 ; i++){
			usleep(100000);
			cout << endl;
		}

}
