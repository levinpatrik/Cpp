#ifndef WEAPON_H
#define WEAPON_H
#include "Item.hpp"



class Weapon : public Item{


	public:
		//	CONSTRUCTORS
		Weapon()
		{
			std::cout << "Default constructor Item" << std::endl;
		}
		Weapon(int weight, int price, int atk,  std::string description);
		~Weapon();

		//	VIRTUAL FUNCTIONS
		virtual std::string description() const override;


};


#endif