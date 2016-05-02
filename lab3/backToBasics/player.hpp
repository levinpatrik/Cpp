#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <iostream>
#include "item.hpp"

// TODO: -make getters return 
	  // -rename the functions get/set/remove
	  //Make new structure: get-> returns obj,  set-> takes obj  print-> prints descriptions/variables

namespace game
{
class Player
{
public:
	Player();
	Player(std::string name_In, int hp_In, int attackpower_In);
	Player(const Player &);
	~Player();

	void attack(Player *);
	void equip();
	void unequip();
	std::vector<Item *>  deathAction();

	//Print
	void printDescription() const;
	void printName() const;
	void printInventory() const ;
	void printEquiped() const;

	
	//Getters
	std::string getName() const ;
	int getAtk();
	int getHp();
	Item * getItem(std::string);

	//Setters
	void setItem(Item * i);
	void setHp(int dmg);
	void setAtk(int atk);

	//Removers
	void removeItem(std::string item_name);

	
	void debug(std::string s)
	{
		std::cout << s << std::endl;
	}

protected:
	std::string name;
	int hp;
	int attackpower;
	int nrOfItems;
	std::vector<Item *> inventory;
	std::vector<Item *> equiped;
};
}	//end namespace
#endif