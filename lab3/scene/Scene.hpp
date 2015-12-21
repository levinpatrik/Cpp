#pragma once
#include "../character/Character.hpp"
#include "../item/Item.hpp"
#include <string.h>

class Scene{
	public:

		//Constructors
		Scence();

		//Destructor
		~Scence();



	protected:

		//Member functions
		virtual available_directions() = 0; // returns the available exits
		virtual const Scene& neighbor(direction) const = 0; // returns the neighbor in that direction 
		virtual std::string description() const = 0; // returns a description of the environment and units
		virtual void enter(const Character&) = 0; // character arrived to scene
		virtual void leave(const Character&) = 0; // character leaves the spot
		virtual void pick_up(const Item&) = 0; // takes an object from the scene
		virtual void drop(const Item&) = 0; // drops an object at the location

		std::vector<Object> objects;
		std::vector<Character> characters;
		std::string standard_description;	

};