#include "Animal.hpp"

//----------------------------
//------ CONSTRUCTORS  ------
//----------------------------
Animal::Animal()
{
	debug("Animal Default constructor");
}

Animal::Animal(std::string name_In, int hp_In, int attackpower_In)
{
	debug("Animal SELF-");
	name = name_In;
	hp = hp_In;
	attackpower = attackpower_In;
	inventory = {};
	equiped = {};
}
Animal::Animal(const Animal &)
{
	debug("Animal Copy constructor");
}

Animal::~Animal()
{
	debug("Animal destructor constructor");
}

//----------------------------
//------ FUNTIONALLITY  ------
//----------------------------
void Animal::attack(Player * p)
{
	debug("Animal ATTACK");

	std::cout << name << " goes berserk!" <<std::endl;

	for(int i = 0; i < 2; i++)
	{
		auto player_hp_before = p->getHp();
		auto player_hp_after = player_hp_before - attackpower;
		std::cout << name << " attacked " << p->getName() << std::endl;
		std::cout << p->getName() << " went from " << player_hp_before << " to " << player_hp_after << " hp." << std::endl;
		p->setHp(player_hp_after);
	}
}

std::vector<Item *> Animal::deathAction()
{
	debug("Animal DEATHACTION");

	std::cout << name << " was defeated!" << std::endl;
	std::cout << name << " thrashes violently before it finally collapses." << std::endl;
	if(inventory.size() > 0)
	{
		std::cout <<"It droped ";
		printInventory();
	}
	else
	{
		std::cout << "It dropped nothing!" << std::endl;
	}

	return inventory;
}























