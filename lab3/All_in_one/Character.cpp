#include "Character.hpp"

void Character::add(const Item & i)
{
	const Item * i_p = &i;
	inventory.push_back(i_p);
	std::cout << "Added " << i_p->description() << std::endl;
}

void Character::move(std::string direction)
{
	std::cout<< "Move: " << direction << std::endl;
}
