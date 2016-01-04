#pragma once
#include "../character/Character.hpp"
#include "../item/Item.hpp"
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

class Scene{
	public:

		//Constructors
		Scene();

		//Destructor
		~Scene();

		//Member functions
		void enter(const Character&); // character arrived to scene
		void leave(const Character&); // character leaves the spot
		void pick_up(const Item&);    // takes an object from the scene
		void drop(const Item&);       // drops an object at the location

		std::string directions() const;  // returns the available exits
		Scene neighbor() const; // returns the neighbor in that direction 
		std::string description() const; // returns a description of the environment and units

	protected:
		std::vector<const Item&> the_items;
		std::vector<const Character&> the_characters;
		std::string standard_description;	

};