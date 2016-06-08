#include "item.hpp"
using namespace game;

Item::Item()
{
	debug("ITEM DEFAULT-");
	price = 0;
	atk = 0;
	stamina = 0;
	name = "-";
	description = "-";
}

Item::Item(const Item & i)
{
	debug("ITEM COPY-");
	price = i.price;
	atk = i.atk;
	stamina = i.stamina;
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

Item::Item(std::string description_In, std::string name_In, int price_In, int atk_In, int stamina_In)
{
	debug("ITEM SELF- price + atk");
	description = description_In;
	name = name_In;
	price = price_In;
	atk = atk_In;
	stamina = stamina_In;
}


Item::~Item()
{
	debug("ITEM DESTRUCTOR");
	std::cout << getName() <<  this << std::endl;

}

//----------------------------
//------ 	PRINTS		------
//----------------------------
void Item::printDescription()
{
	std::cout <<"a " << name << "." << std::endl;
	std::cout << description << std::endl;
	std::cout << "It is worth: " << price << std::endl;
	std::cout << "It has " << atk << " attackpower and " << stamina << " stamina."<< std::endl;

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

int Item::getAtk() const
{
	return atk;
}
int Item::getStamina() const
{
	return stamina;
}


//----------------------------
//------ 	SETTERS		------
//----------------------------

