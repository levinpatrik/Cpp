#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item
{
	public:
		//	CONSTRUCTORS
		virtual ~Item()
		{
			std::cout << "Virtual destructor Item" << std::endl;
		}



		//	PURE-VIRTUAL FUNCTIONS
		virtual std::string description() const = 0;

		//	FUNCTIONS 
		unsigned price() const {return the_price;}
		unsigned weight() const {return the_weight;}
	protected:
		unsigned int the_weight;
		unsigned int the_price;
		int the_attackpower;
		std::string the_description;
};

#endif