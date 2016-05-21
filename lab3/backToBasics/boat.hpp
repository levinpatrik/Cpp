#ifndef BOAT_H
#define BOAT_H
#include "scene.hpp"


namespace game
{

class Boat : public Scene
{
public:


	Boat();
	Boat(const Boat &);
	Boat(std::string description_In);
	virtual ~Boat();


	virtual bool entryRequirments(Player * p_p) const 
	{
		auto i_p = p_p->getItem("key");

		if(i_p != NULL)
		{
			std::cout << "By using your key you are able to use the boat to escape the island!" << std::endl;
			std::cout << "YOU ARE VICTORIOUS! " << std::endl;
			usleep(10000000);
			return 1;
		}
		else
		{
			std::cout << "The boat is chained in place. You need to find a way to unlock it!" << std::endl;
			return 0;//print error why you cant enter
		}
	}
};
}

#endif