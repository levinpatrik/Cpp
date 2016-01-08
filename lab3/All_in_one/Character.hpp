#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "../item/Item.hpp"
#include <iostream>


class Character{

	public:
		//	CONSTRUCTORS
		virtual ~Character(){
			std::cout << "Virtual destructor Character" << std::endl;
		}

		//	PURE VIRTUAL (ALL MOST HAVE!)
		virtual std::string type() const = 0;
		virtual std::string name() const = 0;
		virtual std::string description() const = 0;
		virtual std::string attacked(int) = 0;
		virtual void action() = 0;


		//	VIRTUAL (MIGHT WANT ONE!)
		virtual void drop(){}
		virtual std::string talk(std::string s){return "Unable to talk.";}
		virtual void attack(Character &){}

		//	FUNCTIONS
		void add(const Item & i);
		void move(std::string direction);

	protected:
		// ATTRIBUTES 
		int hitpoints;
		int attackpower;
		std::vector<const Item *> inventory = {};

};

#endif  