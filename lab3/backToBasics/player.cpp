#include "player.hpp"

using namespace game;
Player::Player()
{
	debug("PLAYER DEFAULT-");
	hp = 0;
	attackpower = 0;
	name = "-";
	inventory = {};
	nrOfItems = 0;
}
Player::Player(std::string name_In, int hp_In, int attackpower_In)
{
	debug("PLAYER SELF-");
	name = name_In;
	hp = hp_In;
	attackpower = attackpower_In;
	inventory = {};
	nrOfItems = 0;
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
	auto player_hp = p->getHp();
	p->setHp(player_hp - attackpower);

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
	std::cout << "Number of item: " << nrOfItems << std::endl;
	for(auto it = inventory.begin(); it != inventory.end(); ++it)
	{
		(*it)->printDescription();
	}

}

void Player::printName() const
{
	std::cout << name << std::endl;
}




//----------------------------
//------ 	GETTERS		------
//----------------------------
std::string Player::getName() const
{
	return name;
}

Item * Player::removeItem(std::string item_name)
{
	Item * tmp = NULL;
	if(nrOfItems > 0)
	{
		for(auto it = inventory.begin(); it != inventory.end(); ++it)
		{
			if((*it)->getName() == item_name)
			{
				tmp = (*it);
				inventory.erase(it);
				nrOfItems--;
				return tmp;
			}
		}
	}
	return tmp;
}

int Player::getAtk()
{
	return attackpower;
}
int Player::getHp()
{
	return hp;

}


//----------------------------
//------ 	SETTERS		------
//----------------------------

void Player::setItem(Item * i)
{
	inventory.push_back(i);
	nrOfItems++;
}

void Player::setAtk(int atk)
{
	attackpower = atk;
}

void Player::setHp(int hitpoints)
{
	hp = hitpoints;
}




