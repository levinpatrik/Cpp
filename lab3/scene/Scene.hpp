#ifndef SCENE_H
#define SCENE_H

#include "../character/Character.hpp"
#include "../item/Item.hpp"
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Scene{
	public:

		Scene();

		//Member functions
		void enter(const Character&); // character arrived to scene
		void leave(const Character&); // character leaves the spot
		void pick_up(const Item&);    // takes an object from the scene
		void drop(const Item&);       // drops an object at the location
		


		std::string directions() const;  // returns the available exits
		Scene neighbor() const; // returns the neighbor in that direction 
		std::string description() const; // returns a description of the environment and units
		void alter_connections(const char&, Scene&);
		const Scene get_connections(const char&)const;

		//operator overload
		// Scene& operator=(const Scene&);



	protected:
		std::vector<const Item *> the_items = {};
		std::vector<const Character *> the_characters = {};
		std::string standard_description;
		std::map<char, Scene*> environment; 	


};

#endif