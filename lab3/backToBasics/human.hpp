#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "player.hpp"

using namespace game;
class Human: public Player
{

public:
	Human();
	Human(std::string name_In, int hp_In, int attackpower_In);
	Human(const Human &);
	~Human();

	virtual void attack(Player *) override;
	virtual std::vector<Item *>  deathAction() override;

protected:

};

#endif