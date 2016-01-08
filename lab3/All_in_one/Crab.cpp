#include "Crab.hpp"
using namespace std;

//		---		CONSTRUCTORS		---
Crab::Crab()
{
	cout << "Default construtor Crab" << endl;
	attackpower = 0;
	hitpoints 	= 10;
	//inventory.push("skiten som ska droppas")

}

Crab::Crab(const Crab & a)
{
	cout << "Copy constructor Crab" << endl;
	attackpower = a.attackpower;
	hitpoints = a.hitpoints;
}

Crab::~Crab()
{
	//Ta bort nått skit?
	//Typ att den inte ska vara i rummet / delete minne

}


//		MEMBER FUNCIONS
std::string Crab::description() const 
{return "This is a good description of a crab";}


std::string Crab::name() const
 {return "Crab";}

 void Crab::drop()
 {
 	std::cout << "In drop" << std::endl;
 }

 void Crab::attack(Character & c)
 {
 	std::cout << "In attack" << std::endl;

 }

 void Crab::action()
 {
 	std::cout << "In action" << std::endl;
 }