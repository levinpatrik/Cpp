#include "human.hpp"

//----------------------------
//------ CONSTRUCTORS  ------
//----------------------------
Human::Human()
{
	debug("HUMAN Default constructor");
}

Human::Human(std::string name_In, int hp_In, int attackpower_In)
{
	debug("HUMAN SELF-");
	name = name_In;
	hp = hp_In;
	attackpower = attackpower_In;
	inventory = {};
	equiped = {};
}
Human::Human(const Human &)
{
	debug("HUMAN Copy constructor");
}

Human::~Human()
{
	debug("HUMAN destructor constructor");
}

//----------------------------
//------ FUNTIONALLITY  ------
//----------------------------
void Human::attack(Player * p)
{
	debug("HUMAN ATTACK");

	auto player_hp_before = p->getHp();
	auto player_hp_after = player_hp_before - attackpower;
	
	if(getHp() >= 2)
	{
		std::cout << name << " yells: I WILL CRUSH YOU!" << std::endl;
	}

	std::cout << name << " attacked " << p->getName() << std::endl;
	std::cout << p->getName() << " went from " << player_hp_before << " to " << player_hp_after << " hp." << std::endl;
	p->setHp(player_hp_after);
}

std::vector<Item *> Human::deathAction()
{
	debug("HUMAN DEATHACTION");

	std::cout << name << " was defeated!" << std::endl;
	std::cout << name << " say: DAMN YOU, DAMN YOU ALL TO HELL!!!" << std::endl;
	if(inventory.size() > 0)
	{
		std::cout <<"He droped ";
		printInventory();
	}
	else
	{
		std::cout << "He dropped nothing!" << std::endl;
	}

	return inventory;
}























