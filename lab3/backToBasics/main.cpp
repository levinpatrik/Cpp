#include "player.hpp"
#include "scene.hpp"
#include "item.hpp"

#include <iostream>
#include <assert.h>
#include <string> 

using namespace std;
using namespace game;


class Test
{

public:
void f1()
{
	cout << "Test::f1"  << endl;
}
void f2()
{
	cout << "Test::f2"  << endl;
}

};


int main()
{

	cout << "MAIN" << endl;
	cout << "------	ITEM TESTS ------" << endl;
	{
		Item i1;
		Item i2("its shiny", "sword", 10);
		assert (i1.getDescription() == "-");
		assert (i1.getPrice() == 0);
		assert (i1.getName() == "-");

		assert (i2.getDescription() == "its shiny");
		assert (i2.getPrice() == 10);
		assert (i2.getName() == "sword");
	}

	cout << "------	PLAYER TESTS ------" << endl;
	{
		// ---- getName -----
		Player c1;
		assert( c1.getName() == "-");
		Player c2("another name", 10, 10);
		assert( c2.getName() == "another name");

		// ---- getAtk -----
		assert( c1.getAtk() == 0);	
		assert( c2.getAtk() == 10);	

		// ---- setAtk -----
		c1.setAtk(5);
		c2.setAtk(6);
		assert( c1.getAtk() == 5);	
		assert( c2.getAtk() == 6);

		// ---- getHp -----
		assert( c1.getHp() == 0);	
		assert( c2.getHp() == 10);	

		// ---- setHp -----
		c1.setHp(5);
		c2.setHp(6);
		assert( c1.getHp() == 5);	
		assert( c2.getHp() == 6);

		// ---- setItem / removeItem -----
		Item i1("a green shield", "shield", 10);
		Item i2("a red sword", "sword", 10);
		Item i3("a blue Helmet", "helmet", 1);
		Item i4;
		Item * tmp = &i4;
		tmp = c1.removeItem("adabdad");
		c1.setItem(&i1);
		c1.setItem(&i2);
		c1.setItem(&i3);
		c1.setItem(&i4);
		c1.removeItem("shield");
		c1.removeItem("sword");
		tmp = c1.removeItem("helmet");
		tmp = c1.removeItem("-");	
	}

	cout << "------	SCENE TESTS ------" << endl;
	{

		//---  PRINTS  ---
		Scene s1("Another place");
		Scene s2("A beach");
		Scene s3("A beach2");

		Item i1;
		Item i2("its shiny", "sword", 10);

		//---  SETTERS  ---
		s1.setItem(&i1);
		s1.setItem(&i2);
		s1.printItems();
		
		Item * i_p = &i1;
		i_p = s1.removeItem("sword");
		assert(&i2 == i_p);
		i_p = s1.removeItem("-");
		assert(&i1 == i_p);
		s1.printItems();

		Player p1("Monster1",10,10);
		Player p2("Monster2",10,10);
		Player p3("Player",10,10);		

		s1.setPlayer(&p1);
		s1.setPlayer(&p2);
		s1.setPlayer(&p3);
		s1.printPlayers();
		s1.removePlayer("Monster1");
		s1.removePlayer("Monster2");
		s1.removePlayer("Player");
		s1.printPlayers();


		s1.printExits();
		s1.setExit("e", &s2);
		s1.setExit("w", &s2);
		s1.setExit("s", &s3);
		s1.setExit("n", &s3);
		s1.printExits();

		Scene * s_p;
		s_p = s1.removeExit("e");
		s_p = s1.removeExit("w");
		s_p = s1.removeExit("n");
		s_p = s1.removeExit("s");
		s1.printExits();
	}


	cout << "------	CIN test ------	" << endl;
	{
		// cout << "which function do you want to call?" << endl;
		// std::string a;
		// cin >> a;


		Scene s("A desctiption");
		Player p("player", 10, 1);
		Player m("monster", 5, 1);
		Player m2("boss", 50, 1);
		s.setPlayer(&p);
		s.setPlayer(&m);
		s.setPlayer(&m2);
		// s.printPlayers();

		// auto p_p = s.action();
		// p_p->printName();
		// p_p = s.action();
		// p_p->printName();
		// p_p = s.action();
		// p_p->printName();

		std::string action_str;
		std::string target_str;
		Player * p_tmp;

		Player * t = NULL;
		typedef void (Player::*MFP)(Player *);
   		std::map <std::string, MFP> fmap;
		fmap.insert(std::make_pair("atk", &Player::attack));
		// (t->*f_ptr)();

		while(1)
		{
			auto p_p = s.action();
			if(p_p->getName() == "player")
			{
				cout << "What do you want to do? " << endl;
				cin >> action_str;
				cout << "Who do you want to attack? " << endl;
				cin >> target_str;

				MFP f_ptr = fmap[action_str];
				p_tmp = p_tmp = s.getPlayer(target_str);
				cout << "monster hp: " <<  p_tmp->getHp() << endl;
				p_p->attack(p_tmp);
				cout << "monster hp: " << p_tmp->getHp() << endl;
			}
			else
			{
				p_tmp = s.getPlayer("player");
				cout << "player hp: " << p_tmp->getHp() << endl;
				p_p->attack(p_tmp);
				cout << "player hp: " <<p_tmp->getHp() << endl;
			}
		}

		// få player att attackera monster
		//	1) hämta den som ska göra någonting
		//	2) läs in vad som ska göras
		//  3) gör det


		// auto p_ptr = s.getPlayer("player");
		// p_ptr->attack(s.getPlayer("monster"));




		// void (Test::*fptr) (std::string) = &Test::f1; 	//Declare a function pointer return (Class::*f_ptr)(input type)



		// Test t;
		// void (Test::*fptr) (std::string) = &Test::f1; 	//Declare a function pointer return (Class::*f_ptr)(input type)
		// (t.*fptr)(a);



		// std::map<std::string, Test *> test_map;

		// std::pair<std::string, Test *> pair_a = std::make_pair("f1", f_ptr);
		// test_map.insert("f1" , f_ptr));



		

		
		// Scene s("FUNCTION PTR");
		// Scene * s_p = &s;







	}



	return 0;

}