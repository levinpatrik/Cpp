#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "../item/Item.hpp"
#include <iostream>


class Character{

	public:
		//	CONSTRUCTORS


		//	PURE VIRTUAL
		virtual std::string type() const = 0;
		virtual std::string name() const = 0;
		virtual std::string description() const = 0;
		virtual void action() = 0;

		//	FUNCTIONS
		void move(std::string direction){std::cout<< "move: " << direction << std::endl;};

	protected:
		// ATTRIBUTES 
		int hitpoints;
		int attackpower;
		std::vector<Item> inventory = {};

};

#endif  