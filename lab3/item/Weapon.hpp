#ifndef WEAPON_H
#define WEAPON_H
#include "Item.hpp"



class Weapon : public Item{


	public:
		//	CONSTRUCTORS
		Weapon(int weight, int price, int atk,  std::string description);


		//	VIRTUAL FUNCTIONS
		virtual std::string description() const override;

	protected:
		int weapon_attackpower;
		std::string weapon_description;


};


#endif