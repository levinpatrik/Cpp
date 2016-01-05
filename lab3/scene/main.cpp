#include "Room.hpp"
#include "Cave.hpp"
#include "Jungle.hpp"
#include "Beach.hpp"
#include "Boat.hpp"
#include <iostream>

void build_world(std::vector<Scene*> & test){
	std::string s = "You look around and see a beach to the left";
	Beach start(s);
	std::string description2 = "You look around and see a beach to the right";
	Beach b1(description2);

	start.west = &b1;
	b1.east = &start;

	Scene* p1 = &start;
	Scene* p2 = &b1;
	test.push_back(p1);
	test.push_back(p2);
	
	// Beach* b2;
	// b2 = new Beach(description2);
	// start.west = b2;
	// b2->east = &start;
}

int main(){
	// Room room
	
	std::vector<Scene*> test;
	build_world(test);
	std::cout << test[0]->description() << std::endl;
	std::cout << test[0]->west->description() << std::endl;


	// std::cout << b.description() << std::endl;
	// Beach test = build_world();

	// delete start.west;
	return 0;
}