#include "player.hpp"
#include "scene.hpp"
#include "item.hpp"

#include <iostream>
#include <assert.h>
#include <string> 
#include <sstream>

using namespace std;
using namespace game;


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
void f1(std::string s)
{
	cout << "Test::f1"  << s << endl;
}
void f2(std::string s)
{
	cout << "Test::f2"  << s << endl;
}


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
	
	cout << "------	Read input TESTS ------" << endl;
	{
    std::string input;
    getline( std::cin, input );
	std::vector<std::string> input_vec;
	char delim = ' ';
	input_vec = split(input, delim);
	for(int i = 0; i < input_vec.size(); i++)
	{
		cout << input_vec[i] << endl;
	}



	}
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

	cout << "------	MAP test ------	" << endl;
	{
		Test T;
		Bar B;
		GameItem * G_p = &B;


		// game_fp func_p = &GameItem::virtFunc;
		// (G_p->*func_p)("en string");
		


		typedef void (Test::*test_fp)(std::string);
		typedef void (Bar::*bar_fp)(std::string);
		typedef void (GameItem::*game_fp)(std::string);

		//Function ptr maps
  		std::map <std::string, test_fp> testFunc_map;
  		std::map <std::string, bar_fp> barFunc_map;
  		std::map <std::string, game_fp> gameFunc_map;


  		//Object ptr maps
  		std::map<std::string, Test *> testObj_map;
  		std::map<std::string, Bar *> barObj_map;
  		std::map<std::string, GameItem *> gameObj_map;

		testFunc_map.insert(std::make_pair("f1", &Test::f1));
  		testFunc_map.insert(std::make_pair("f2", &Test::f2));

		barFunc_map.insert(std::make_pair("foo1", &Bar::foo1));
		barFunc_map.insert(std::make_pair("foo2", &Bar::foo2));

		testObj_map.insert(std::make_pair("t", &T));
		barObj_map.insert(std::make_pair("b", &B));

		gameFunc_map.insert(std::make_pair("virt", &GameItem::virtFunc));
		gameObj_map.insert(std::make_pair("game", G_p));


		// auto g_1 = gameFunc_map.find("virtFunc");
		// auto g_func = g_1->second;
		// auto g_2  = gameObj_map.find("game");
		// auto g_obj = g_2->second;

		// (g_obj->*g_func)("en string");










		std::cout <<"call fun: " << endl;
		std::string a;
		std::cout <<"on obj: " << endl;
		std::string b;
		
	while(1)
	{
		cin >> a;
		cin >> b;

		auto it_1 = barFunc_map.find(a);
		auto it_2 = testFunc_map.find(a);
		auto it_6 = gameFunc_map.find(a);
		auto it_3 = testObj_map.find(b);
		auto it_4 = barObj_map.find(b);
		auto it_5 = gameObj_map.find(b);

		if(it_1 != barFunc_map.end() && it_4 != barObj_map.end() )
		{
			auto barFunc_p = it_1->second;
			auto barObj_p = it_4->second;
			(barObj_p->*barFunc_p)("BAR!");
		}
		else if(it_2 != testFunc_map.end() && it_3 != testObj_map.end())
		{
			auto testFunc_p = it_2->second;
			auto testObj_p = it_3->second;
			(testObj_p->*testFunc_p)("TEST!");
		}
		else if(it_5 != gameObj_map.end() && it_6 != gameFunc_map.end())
		{

			auto gameobj_p = it_5->second;
			auto gamefunc_p = it_6->second;
			(gameobj_p->*gamefunc_p)("TEST!");


		}
		else
		{
			std::cout << "You can not do that. " << std::endl;
		}			


			// auto test_fptr = it_2->second;
			// (T.*test_fptr)("Hej");
	}
	}	


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