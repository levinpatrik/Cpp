#ifndef CONTAINER_H
#define CONTAINER_H
#include "Item.hpp"
#include <vector>



class Container : public Item{

public:
	//CONSTRUCTOR
	Container(int capacity, int weight, int price, std::string container_description);




	//	VIRTUAL FUNCTIONS
	virtual std::string description() const override;


	//	FUNCTIONS 
	int capacity() const {return the_capacity;}
	int available_capacity() const;
	int pick_up(const Item &);
	int drop(const Item &);



protected: 
	int the_capacity;
	std::string container_description;
	std::vector<Item> container_vec;



		

};
#endif