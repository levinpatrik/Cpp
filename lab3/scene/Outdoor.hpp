#pragma once
#include "Scene.hpp"

class Outdoor: public Scene{
	public:
		//Constructors
		Outdoor():


		//Overloads



	protected:

		//Member functions
		directions(){return 8};
		available_directions(); // returns the available exits
		const Scene& neighbor(direction) const; // returns the neighbor in that direction 
		std::string description() const; // returns a description of the environment and units
		void enter(const Character&); // character arrived to scene
		void leave(const Character&); // character leaves the spot
		void pick_up(const Item&); // takes an object from the scene
		void drop(const Item&); // drops an object at the location


};