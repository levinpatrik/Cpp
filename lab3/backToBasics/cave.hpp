#ifndef CAVE_H
#define CAVE_H
#include "scene.hpp"


namespace game
{

class Cave : public Scene
{
public:


	Cave();
	Cave(const Cave &);
	Cave(std::string description_In);
	virtual ~Cave();


	virtual bool entryRequirments(Player * p_p) const 
	{
		auto i_p = p_p->getItem("lamp");

		if(i_p != NULL)
		{
			std::cout << "With the help of your lamp you are able to enter the cave." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "You need to have a lamp to enter this dark cave." << std::endl;
			return 0;//print error why you cant enter
		}
	}
};
}

#endif