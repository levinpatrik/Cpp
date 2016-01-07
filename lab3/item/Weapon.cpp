#include "Weapon.hpp"


//	---		CONSTRUCTORS		---

Weapon::Weapon(int weight, int price, int atk,  std::string description)
{

	the_weight = weight;
	the_price = price;
	weapon_attackpower = atk;
	weapon_description = description;

}
std::string Weapon::description() const
{
	return "You see a " + weapon_description + "\n"+
	"Stats:" + "\n" + 
	"attack: " + std::to_string(weapon_attackpower) + "\n" +
	"weight: " + std::to_string(the_weight) + "\n" +
	"price: "  + std::to_string(the_price) + "\n" ;

}