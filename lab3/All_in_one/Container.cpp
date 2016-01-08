#include "Container.hpp"
#include <iostream>

//	---		CONSTRUCTORS		---

Container::Container(int capacity, int weight, int price, std::string description)
{
	container_description = description;
	the_capacity = capacity;
	the_weight = weight;
	the_price = price;
}



//	---		MEMBER FUNCTION		---
int Container::available_capacity() const
{
	int item_counter = 0;
	//Loop through container vec and a add to counter for each item
	int available_capacity = (the_capacity - item_counter);
	return available_capacity;

}

int Container::pick_up(const Item & i)
{
	//push_back item in vector 
	//Remove from scene

	std::cout << "inside pick_up" << std::endl;
	return -1;

}

int Container::drop(const Item & i)
{
	//Drop item on scene
	//Remove item from vector 
	return -1;
}

std::string Container::description() const
{
	return "You see a " + container_description + "\n"+
	"Stats:" + "\n" + 
	"weight: " + std::to_string(the_weight) + "\n" +
	"price: "  + std::to_string(the_price) + "\n"
	"capacity: " + std::to_string(the_capacity) + "\n";

}






