#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "player.hpp"

using namespace game;
class Animal: public Player
{

public:
	Animal();
	Animal(std::string name_In, int hp_In, int attackpower_In);
	Animal(const Animal &);
	~Animal();

	virtual void attack(Player *) override;
	virtual std::vector<Item *>  deathAction() override;

protected:

};

#endif