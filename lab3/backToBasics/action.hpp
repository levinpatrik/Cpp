#ifndef ACTION_H
#define ACTION_H
#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "scene.hpp"
#include "player.hpp"
#include "item.hpp"

namespace game
{
class Action
{

	Action(Scene * current);

	void go(Player * who, std::string where);
 	void attack(Player * attacker, Player * attacked);
 	void drop(Player * p_from);
 	void pickup(Player * p_to);



	Scene * current_scene;

};
}

#endif