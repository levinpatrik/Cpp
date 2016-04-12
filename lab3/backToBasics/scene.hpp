#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "player.hpp"
#include "item.hpp"


//TODO: - OM scene har 0 players kommer det bli segmentation fault på action?

namespace game
{
	
class Scene{

public:
	
	Scene();
	Scene(const Scene &);
	Scene(std::string description_In);
	~Scene();


	//void go(Player * vem, direction var)
	//void pickup(Player * vem, Item * vad) -> vad finns i Scene?
	//void drop(Player * vem, Item * vad)   ->

	void go(std::string s);
	void pickup(std::string s);
	void drop(std::string s);

	Player * action();



	//Prints
	void printDescription() const;						//print description of the Scene 
	void printItems() const;							//print available items in the Scene
	void printPlayers() const;							//print avialable players in the Scene
	void printExits() const;							//print available exits in the Scene


	//Setters
	void setItem(Item *);								//Add Item to item_vec
	void setPlayer(Player *);							//Add player in player_vec
	void setExit(std::string name, Scene* scene_p);		//Add an exit to exits_map

	//Getters
	Item * getItem(std::string item_name);				//Get item_name from item_vec
	Player * getPlayer(std::string name);				//Get player from player_vec
	Scene * getExit(std::string name);					//Get exit from exit_map
	
	//Removers
	Item * removeItem(std::string item_name);			//Remove item_name from item_vec
	Player * removePlayer(std::string name);			//Remove player from player_vec
	Scene * removeExit(std::string name);				//Remove exit from exit_map




	void debug(std::string s)
	{
	//std::cout << s << std::endl;
	}
protected:
	int currentPlayer;
	std::string description;
	std::vector<Item *> item_vec;					//Items currently in Scene
	std::vector<Player *> player_vec;				//Players currently in Scene
	std::map<std::string, Scene*> exits_map;		//Map's a string to a exit obj_ptr
};
}	//end namespace

#endif