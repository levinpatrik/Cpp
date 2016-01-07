#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
	public:
		//	PURE-VIRTUAL FUNCTIONS
		virtual std::string description() const = 0;

		//	FUNCTIONS 
		unsigned price() const {return the_price;}
		unsigned weight() const {return the_weight;}
	protected:
		unsigned int the_weight;
		unsigned int the_price;
};

#endif