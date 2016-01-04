#include "Merchant.hpp"
using namespace std;

//		---		CONSTRUCTORS		---

Merchant::Merchant()
{
	cout << "Default construtor Merchant" << endl;
	attackpower = 0;
	hitpoints 	= 10;
	//inventory.push("skiten som ska droppas")

}
Merchant::Merchant(const Merchant & m)
{
	cout << "Copy constructor Merchant" << endl;
	attackpower = m.attackpower;
	hitpoints = m.hitpoints;
}

Merchant::~Merchant()
{
	//Ta bort nått skit?
	//Man kanske ska newa i constructorn?

}





//		---		MEMBER FUNCIONS		---
std::string Merchant::description() const 
{return "This is a good description of a Merchant";}


std::string Merchant::name() const
{return "Merchant";}

void Merchant::drop(const Item &)
{
std::cout << "In drop" << std::endl;
}

void Merchant::attack(Character const & c)
{
	std::cout << "In attack" << std::endl;

}

void Merchant::action()
{
	std::cout << "In action" << std::endl;
}


std::string Merchant::talk(std::string s)
{
	std::cout << "Inside talk, do somthing fancy here" << std::endl;
	return "Answer";
}