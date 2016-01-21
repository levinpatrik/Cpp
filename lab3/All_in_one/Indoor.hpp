#ifndef INDOOR_H
#define INDOOR_H
#include "Scene.hpp"

class Indoor : public Scene{

	public:


	protected:
		Scene* forward  = NULL;
		Scene* right    = NULL;
		Scene* backward = NULL; 
		Scene* left     = NULL;
		
};

#endif