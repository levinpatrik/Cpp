#include "player.hpp"
#include "scene.hpp"
#include "item.hpp"

//Virtual classes
#include "human.hpp"
#include "animal.hpp"


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
	cout << "------	VIRTUAL TEST ------	" << endl;
	{
		Human h1;
		Player * h1_pp = &h1;
		Human h2;
		Player * h2_pp = &h2;

		Player p;
		Player * p_p = &p;

		// Animal a;
		// Player * c_p2 = &a;

		//ATTACK
		{

			p_p->attack(&h1);
			h1_pp->attack(&h2);
			h2_pp->attack(&h1);
		}

		// //DEATHACTION
		// {
		// 	c_p1->deathAction();
		// 	c_p2->deathAction();
		// }

		// //EQUIP & UNEQUIP
		// {	
		// 	Item i("a test item","test", 1,1,1);
		// 	c_p1->setItem(&i);
		// 	c_p1->equip();
		// 	c_p1->unequip();
		// }
	}

	cout << "------	A MAP ------	" << endl;
	{
		//---  CONSTRUCT ALL SCENES ---
		Scene s1("Startzone");
		Scene b1("beach1");
		Scene b2("beach2");
		Scene b3("beach3");
		Scene c("cave");
		Scene h("house");


		//---  CONSTRUCT ALL ITEMS ---
		Item cup("It can be used as a 'hat'..", "cup", 0, 0, 1);
		Item sword("It looks rusty", "sword", 10, 3 , 0);
		Item shell("It can be used as a shield", "shell", 10, 0 , 3);
		Item hat("Its dajm ugly", "hat",0,0,0);
		Item trophy("It means you're done!","trophy",100,0,0);


		//---  CONSTRUCT ALL PLAYERS ---
		Player main_char("Player",4,2);
		Player crab("crab",4,2);
		Player rat1("rat1",1,1);
		Player rat2("rat2",1,1);
		Player boss("big-ass-boss", 5,5);
		Human test("test",4,1);

		//BASECLASS POINTER
		Player * player_p = &test;


		//---  LINK ALL SCENES ---
		s1.setExit("north",&b1);

		b1.setExit("south",&s1);
		b1.setExit("east",&b2);

		b2.setExit("west",&b1);
		b2.setExit("east",&h);
		b2.setExit("north",&b3);

		h.setExit("west", &b2);

		b3.setExit("north",&c);



		//---  SET ALL PLAYERS ---
		s1.setPlayer(player_p);
		s1.setPlayer(&main_char);
		b1.setPlayer(&crab);
		b2.setPlayer(&rat1);
		b2.setPlayer(&rat2);
		c.setPlayer(&boss);


		//---  SET ALL ITEMS ---
		s1.setItem(&cup);
		crab.setItem(&shell);
		h.setItem(&sword);
		h.setItem(&hat);
		boss.setItem(&trophy);

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
		cout << "You are in ";
		current_scene_p->printDescription();
		cout << "." << endl;
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
				auto tmpS_p = current_scene_p->go();
				if(tmpS_p != NULL)
				{
					current_scene_p = tmpS_p;
					cout << string( 100, '\n' );
					cout << "You are in ";
					current_scene_p->printDescription();
					current_scene_p->printPlayers();
					current_scene_p->printItems();
					current_scene_p->printExits();
				}
			}
			else
			{
				cout << "'"<< a <<"' is not a valid option" << endl;
				auto tmp_scene_p = current_scene_p->go();
				if(tmp_scene_p != NULL)
				{
					current_scene_p = tmp_scene_p;
				}
			}
		}
		gameOver();
	}


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
