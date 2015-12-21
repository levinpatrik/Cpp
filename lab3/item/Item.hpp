#ifndef ITEM_H
#define ITEM_H

class Item
{
	public:
		unsigned weigth() const {return the_weigth;}
		unsigned volume() const {return the_volume;}
		unsigned price() const {return the_price;}

	protected:
		unsigned int the_weigth;
		unsigned int the_volume;
		unsigned int the_price;
};

#endif