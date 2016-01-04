#pragma once
#include "Scene.hpp"

class Outdoor: public Scene{
	public:
		//Constructors
		Outdoor():


		//Overloads



	protected:

		//Member functions
		virtual std::string directions() const; // returns the available exits
		virtual const Scene& neighbor(direction) const; // returns the neighbor in that direction 
		virtual std::string description() const; // returns a description of the environment and units
		virtual void enter(const Character&); // character arrived to scene
		virtual void leave(const Character&); // character leaves the spot
		virtual void pick_up(const Item&); // takes an object from the scene
		virtual void drop(const Item&); // drops an object at the location


};