#include "Ape.hpp"
using namespace std;

//		---		CONSTRUCTORS		---
Ape::Ape()
{
	cout << "Default construtor Ape" << endl;
	attackpower = 0;
	hitpoints 	= 10;
	//inventory.push("skiten som ska droppas")

}

Ape::Ape(const Ape & a)
{
	cout << "Copy constructor Ape" << endl;
	attackpower = a.attackpower;
	hitpoints = a.hitpoints;
}

Ape::~Ape()
{
	//Ta bort nått skit?
	//Man kanske ska newa i constructorn?

}



//	-----		MEMBER FUNCIONS		-----
std::string Ape::description() const 
{return "This is a good description of a Ape";}


std::string Ape::name() const
 {return "Ape";}

 void Ape::drop()
 {
 	std::cout << "In drop" << std::endl;
 }

 void Ape::attack(Character & c)
 {
 	std::cout << "In attack" << std::endl;

 }

 void Ape::action()
 {
 	std::cout << "In action" << std::endl;
 }