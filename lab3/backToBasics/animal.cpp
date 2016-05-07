#include "animal.hpp"

//----------------------------
//------ CONSTRUCTORS  ------
//----------------------------
Animal::Animal()
{
	debug("Animal Default constructor");
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
void Animal::attack(Player *)
{
	debug("Animal attack");
}


std::vector<Item *>  Animal::deathAction()
{
	debug("Animal deathAction");
	std::vector<Item *> tmp;
	return tmp;
}
























