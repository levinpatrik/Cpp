#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "player.hpp"

using namespace game;
class Animal: public Player
{

public:
	Animal();
	Animal(const Animal &);
	~Animal();

	virtual void attack(Player *);
	virtual std::vector<Item *>  deathAction();

protected:

};

#endif