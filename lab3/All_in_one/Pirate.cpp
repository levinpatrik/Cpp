#include "Pirate.hpp"
using namespace std;

//		---		CONSTRUCTORS		---
Pirate::Pirate()
{
	cout << "Default construtor Pirate" << endl;
	attackpower = 0;
	hitpoints 	= 10;
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
	cout << "Destructor Pirate" << endl;

}


//		MEMBER FUNCIONS
std::string Pirate::description() const 
{return "This is a good description of a Pirate";}


std::string Pirate::name() const
{return "Pirate";}

void Pirate::drop()
{
std::cout << name() << " drops " << std::endl;
}

void Pirate::attack(Character & c)
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

std::string Pirate::attacked(int i)
{
		std::cout << name() <<" was attacked for " << i << " attackpower." << std::endl;
		hitpoints -= i;
		std::cout << "hitpoints left:" << hitpoints << std::endl;
		if(hitpoints <= 0)
		{
			std::cout << name() << " died!" << std::endl;
			drop();
			//Remove from scene 
		}
		return "AJ";
}





