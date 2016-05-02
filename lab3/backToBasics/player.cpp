#include "player.hpp"

using namespace game;
Player::Player()
{
	debug("PLAYER DEFAULT-");
	hp = 0;
	attackpower = 0;
	name = "-";
	inventory = {};
	equiped = {};
}
Player::Player(std::string name_In, int hp_In, int attackpower_In)
{
	debug("PLAYER SELF-");
	name = name_In;
	hp = hp_In;
	attackpower = attackpower_In;
	inventory = {};
	equiped = {};
}

Player::Player(const Player & c)
{
	debug("PLAYER COPY-");
	hp = c.hp;
	attackpower = c.attackpower;
	name = c.name;

}

Player::~Player()
{
	debug("PLAYER DESTRUCTOR");
}

//----------------------------
//------ 	ACTIONS		------
//----------------------------
void Player::attack(Player * p)
{
	std::cout << name << " attacked " << p->getName() << std::endl;
	auto player_hp_before = p->getHp();
	auto player_hp_after = player_hp_before - attackpower;
	std::cout << p->getName() << " went from " << player_hp_before << " to " << player_hp_after << " hp." << std::endl;
	p->setHp(player_hp_after);
}


void Player::equip()
{
	std::string item_name;
	printInventory();
	std::cout << "What do you want to equip?" << std::endl;
	std::cin >> item_name;
	auto i_p = getItem(item_name);
	if(i_p != NULL)
	{	
		equiped.push_back(i_p);
		attackpower += i_p->getAtk();
		hp += i_p->getStamina();
		removeItem(item_name);
	}
}

void Player::unequip()
{
	std::string item_name;
	std::cout << "You have ";
	printEquiped();
	std::cout << " equiped. " << std::endl;
	std::cout << "What do you want to unequip?" << std::endl;
	std::cin >> item_name;

	Item * tmp = NULL;
	for(auto it = equiped.begin(); it != equiped.end(); ++it)
	{
		if((*it)->getName() == item_name)
		{
			tmp = (*it);
			equiped.erase(it);
			inventory.push_back(tmp);
			attackpower -= tmp->getAtk();
			hp -= tmp->getStamina();
			break;
		}
	}
}

std::vector<Item *> Player::deathAction()
{

	std::cout << name << " was defeated!" << std::endl;
	if(inventory.size() > 0)
	{
		std::cout <<" It droped ";
		printInventory();
	}
	else
	{
		std::cout << "But dropped nothing!" << std::endl;
	}

	return inventory;
}


//----------------------------
//------ 	PRINTS		------
//----------------------------
void Player::printDescription() const
{
	printName();
	printInventory();
}

void Player::printInventory() const
{
	if(inventory.size() != 0)
	{
		std::cout << "Number of item: " << inventory.size() << std::endl;
		for(auto it = inventory.begin(); it != inventory.end(); ++it)
		{
			(*it)->printDescription();
		}
	}
	else
	{
		std::cout << "You have no items in your inventory." << std::endl;
	}

}

void Player::printName() const
{
	std::cout << name << std::endl;
}

void Player::printEquiped() const
{
	for(auto it = equiped.begin(); it != equiped.end(); ++it)
	{
		(*it)->printDescription();
	}
}


//----------------------------
//------ 	GETTERS		------
//----------------------------
std::string Player::getName() const
{
	return name;
}

void Player::removeItem(std::string item_name)
{
	Item * tmp = NULL;
	for(auto it = inventory.begin(); it != inventory.end(); ++it)
	{
		if((*it)->getName() == item_name)
		{
			tmp = (*it);
			inventory.erase(it);
			break;
		}
	}
}

int Player::getAtk()
{
	return attackpower;
}
int Player::getHp()
{
	return hp;

}

Item * Player::getItem(std::string item_name)
{
	Item * tmp = NULL;
	for(auto it = inventory.begin(); it != inventory.end(); ++it)
	{
		if((*it)->getName() == item_name)
		{
			tmp = (*it);
			return tmp;
		}
	}
	return tmp;
}


//----------------------------
//------ 	SETTERS		------
//----------------------------

void Player::setItem(Item * i)
{
	inventory.push_back(i);
}

void Player::setAtk(int atk)
{
	attackpower = atk;
}

void Player::setHp(int hitpoints)
{
	hp = hitpoints;
}




