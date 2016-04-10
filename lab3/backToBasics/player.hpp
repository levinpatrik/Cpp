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

	//Print
	void printDescription() const;
	void printName() const;
	void printInventory() const ;

	
	//Getters
	std::string getName() const ;
	Item * removeItem(std::string item_name);
	int getAtk();
	int getHp();


	//Setters
	void setItem(Item * i);
	void setHp(int dmg);
	void setAtk(int atk);

	void debug(std::string s)
	{
	//std::cout << s << std::endl;
	}

protected:
	std::string name;
	int hp;
	int attackpower;
	int nrOfItems;
	std::vector<Item *> inventory;
};
}	//end namespace
#endif