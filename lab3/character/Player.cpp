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
	//Ta bort nått skit?
	//Man kanske ska newa i constructorn?

}






//		---		MEMBER FUNCIONS		---
std::string Player::description() const 
{return "This is a good description of a Player";}


std::string Player::name() const
{return "Player";}

void Player::drop(const Item &)
{
std::cout << "In drop" << std::endl;
}

void Player::attack(Character const & c)
{
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

void pick_up(const Item &)
{
	cout << "Inside pick_up" << endl;
}



