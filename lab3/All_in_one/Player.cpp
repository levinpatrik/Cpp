#include "Player.hpp"

#include "Merchant.hpp"
using namespace std;

//		---		CONSTRUCTORS		---

Player::Player()
{
	cout << "Default construtor Player" << endl;
	attackpower = 2;
	hitpoints 	= 10;
	money = 0;
	//inventory.push("skiten som ska droppas")

}
Player::Player(const Player & m)
{
	cout << "Copy constructor Player" << endl;
	attackpower = m.attackpower;
	hitpoints = m.hitpoints;
}

Player::~Player()
{
	cout << "Destructor Player" << endl;
}






//		---		MEMBER FUNCIONS		---
std::string Player::description() const 
{return "This is a good description of a Player";}


std::string Player::name() const
{return "Player";}

void Player::drop()
{
std::cout << "In drop" << std::endl;
}

void Player::attack(Character & c)
{
	c.attacked(attackpower);
	std::cout << "In attack" << std::endl;

}

void Player::action()
{
	std::cout << "In action" << std::endl;
}

std::string Player::talk(std::string s)
{
	std::cout << "Inside talk, do somthing fancy here" << std::endl;
	return "Answer";
}


std::string Player::attacked(int i)
{
		std::cout << name() <<" was attacked for" << i << "attackpower" << std::endl;
		return "AJ";
}



