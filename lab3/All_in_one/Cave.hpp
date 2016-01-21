#ifndef CAVE_H
#define CAVE_H
#include "Scene.hpp"

class Cave: public Scene
{
	public:
		Cave(const std::string& info);

	private:
		Scene* backward = NULL;
		Scene* forward  = NULL;	

};

#endif