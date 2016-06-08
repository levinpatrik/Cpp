#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <iostream>
#include "item.hpp"


namespace game
{
class Player
{
public:
	Player();
	Player(std::string name_In, int hp_In, int attackpower_In);
	Player(const Player &);
	virtual ~Player();

	virtual void attack(Player *);
	virtual void equip();
	virtual void unequip();
	virtual std::vector<Item *>  & deathAction();

	//Print
	void printDescription() const;
	void printName() const;
	void printInventory() const ;
	void printEquiped() const;

	
	//Getters
	std::string getName() const ;
	int getAtk();
	int getHp();
	int getStartingHp();
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
	int starting_hp;
	int attackpower;
	int nrOfItems;
	std::vector<Item *> inventory;
	std::vector<Item *> equiped;
};
}	//end namespace
#endif