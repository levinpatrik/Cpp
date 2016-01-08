#include "Weapon.hpp"


//	---		CONSTRUCTORS		---
Weapon::~Weapon()
{
	std::cout << "Destructor Weapon." << std::endl;
}

Weapon::Weapon(int weight, int price, int atk,  std::string description)
{
	the_weight = weight;
	the_price = price;
	the_attackpower = atk;
	the_description = description;

}
std::string Weapon::description() const
{
	return ("You see a " + the_description + "\n"+
	"Stats:" + "\n" + 
	"attack: " + std::to_string(the_attackpower) + "\n" +
	"weight: " + std::to_string(the_weight) + "\n" +
	"price: "  + std::to_string(the_price) + "\n");

}