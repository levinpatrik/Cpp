#include "player.hpp"
#include "cave.hpp"
#include "boat.hpp"
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




int main()
{


	cout << "------	A MAP ------	" << endl;
	{
		//---  CONSTRUCT ALL SCENES ---
		Scene s1("Startzone");
		Scene b1("beach1");
		Scene b2("beach2");
		Scene h("house");
		Scene h2("shed");
		Cave cave("cave");
		Boat boat("boat");



		//---  CONSTRUCT ALL ITEMS ---
		Item * sword = new Item("It looks rusty", "sword", 10, 3 , 0);
		Item * shell = new Item("It can be used as a shield", "shell", 10, 0 , 3);
		Item * hat = new Item("It's quite ugly..", "hat",0,0,0);
		Item * lamp= new Item("This might be usefull later on.. ","lamp",0,0,0);
		Item * key = new Item("A golden key! ","key",0,0,0);


		//---  CONSTRUCT ALL PLAYERS ---
		Player main_char("Player",4,2);
		Player crab("crab",4,2);
		Player rat1("rat1",1,1);
		Player rat2("rat2",1,1);
		Player boss("Boss", 10,1);
		Human pelle("pelle",4,1);
		Animal orm("ormen",3,1);

		//BASECLASS POINTER
		Player * player_p1 = &pelle;
		Player * player_p2 = &orm;


		//---  LINK ALL SCENES ---
		s1.setExit("north",&b1);

		b1.setExit("south",&s1);
		b1.setExit("east",&b2);
		b1.setExit("west", &h2);

		h2.setExit("east", &b1);

		b2.setExit("west",&b1);
		b2.setExit("east",&h);
		b2.setExit("north", &cave);

		h.setExit("west", &b2);

		cave.setExit("south", &b2);
		cave.setExit("north", &boat);


		//---  SET ALL PLAYERS ---
		s1.setPlayer(player_p1);
		s1.setPlayer(player_p2);
		s1.setPlayer(&main_char);
		b1.setPlayer(&crab);
		b2.setPlayer(&rat1);
		b2.setPlayer(&rat2);
		cave.setPlayer(&boss);


		//---  SET ALL ITEMS ---
		crab.setItem(shell);
		boss.setItem(key);
		h.setItem(sword);
		h.setItem(hat);
		h2.setItem(lamp);

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


		cout << string( 100, '\n' );
		cout << "You are stranded on a mysterious island." << endl;
		cout << "There seems to be a lot of wildlife near by." << endl;
		cout << "You need to figure out a way to get of the island!" << endl;
		cout << endl;

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
				auto s_fp = s_it->second; 				//points at correct function
				(current_scene_p->*s_fp)();  			//execute the function

			}

			else if(p_it != player_funcMap.end())		//function found
			{
				auto p_fp = p_it->second; 				//points at correct function
				(main_char.*p_fp)();					//execute the function
			}

			else if(a.compare("go") == 0)
			{
				auto tmpS_p = current_scene_p->go();
				if(tmpS_p != NULL)
				{
					current_scene_p = tmpS_p;
					cout << endl;
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
