#include "item.hpp"
using namespace game;

Item::Item()
{
	debug("ITEM DEFAULT-");
	price = 0;
	name = "-";
	description = "-";
}

Item::Item(const Item & i)
{
	debug("ITEM COPY-");
	price = i.price;
	description = i.description;
	name = i.name;
}

Item::Item(std::string description_In, std::string name_In, int price_In)
{
	debug("ITEM SELF-");
	description = description_In;
	name = name_In;
	price = price_In;
}

Item::~Item()
{
	debug("ITEM DESTRUCTOR");

}

//----------------------------
//------ 	PRINTS		------
//----------------------------
void Item::printDescription()
{
	std::cout << "You see a: " << name << std::endl;
	std::cout << description << std::endl;
	std::cout << "It is worth: " << price << std::endl;
}



//----------------------------
//------ 	GETTERS		------
//----------------------------
std::string Item::getDescription() const
{
	return description;
}

std::string Item::getName() const
{
	return name;
}

int Item::getPrice() const
{
	return price;
}

//----------------------------
//------ 	SETTERS		------
//----------------------------

