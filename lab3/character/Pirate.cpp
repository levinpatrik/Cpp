#include "Pirate.hpp"
using namespace std;

//		---		CONSTRUCTORS		---
Pirate::Pirate()
{
	cout << "Default construtor Pirate" << endl;
	attackpower = 0;
	hitpoints 	= 10;
	//inventory.push("skiten som ska droppas")

}

Pirate::Pirate(const Pirate & a)
{
	cout << "Copy constructor Pirate" << endl;
	attackpower = a.attackpower;
	hitpoints = a.hitpoints;
}

Pirate::~Pirate()
{
	//Ta bort nått skit?
	//Typ att den inte ska vara i rummet / delete minne

}

//		MEMBER FUNCIONS
std::string Pirate::description() const 
{return "This is a good description of a Pirate";}


std::string Pirate::name() const
{return "Pirate";}

void Pirate::drop(const Item &)
{
std::cout << "In drop" << std::endl;
}

void Pirate::attack(Character const & c)
{
	std::cout << "In attack" << std::endl;

}

void Pirate::action()
{
	std::cout << "In action" << std::endl;
}


std::string Pirate::talk(std::string s)
{
	std::cout << "Inside talk, do somthing fancy here" << std::endl;
	return "Answer";
}