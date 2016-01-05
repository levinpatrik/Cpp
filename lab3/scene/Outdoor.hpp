#ifndef OUTDOOR_H
#define OUTDOOR_H
#include "Scene.hpp"

class Outdoor : public Scene {
	public:
		//Constructors
		// Outdoor();
		
		Scene* north_west = NULL;
		Scene* north      = NULL;
		Scene* north_east = NULL;
		Scene* east       = NULL;
		Scene* south_east = NULL;
		Scene* south      = NULL;
		Scene* south_west = NULL;
		Scene* west       = NULL; 

		//Overloads
	protected:
		

};

#endif