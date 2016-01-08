#include "Room.hpp"
#include "Cave.hpp"
#include "Jungle.hpp"
#include "Beach.hpp"
#include "Boat.hpp"
#include <iostream>

// void build_world(std::vector<Scene*>& test){
// 	std::string s = "You look around and see a beach to the left";
// 	Beach start(s);
// 	std::string description2 = "You look around and see a beach to the right";
// 	Beach b1(description2);
// 	std::string west= "west";
// 	start.alter_connections(west,b1);
// 	std::cout << start.description() << std::endl;
// 	std::cout << start.get_connections(west).description() << std::endl;
// 	Scene* start_ptr = &start;
// 	Scene* b1_ptr = &b1;
// 	test.push_back(start_ptr);
// 	test.push_back(b1_ptr);

// }

int main(){

	Jungle  middle_square("You wake up");
	Beach left_square("Maybe take a dip in the ocean");
	Room right_square("Atleast there is a roof over your head");
	Cave upper_square("You try to ignore all the eyes that are watching");
	Jungle lowest_square("You prefer the other part of the Jungle");

	///////////////////////////////////////////////////
	// Fixing connections
	///////////////////////////////////////////////////
	middle_square.alter_connections('w', left_square);
	middle_square.alter_connections('n', upper_square);
	middle_square.alter_connections('e', right_square);
	middle_square.alter_connections('s', lowest_square);

	left_square.alter_connections('e', middle_square);
	right_square.alter_connections('w',middle_square);
	upper_square.alter_connections('s',middle_square);
	lowest_square.alter_connections('n',middle_square);
	////////////////////////////////////////////////////

	std::cout << middle_square.description() << std::endl;
	std::cout << middle_square.get_connections('w').description() << std::endl;	
	std::cout << middle_square.get_connections('e').description() << std::endl;	
	std::cout << middle_square.get_connections('n').description() << std::endl;
	std::cout << middle_square.get_connections('s').description() << std::endl;
	return 0;
}