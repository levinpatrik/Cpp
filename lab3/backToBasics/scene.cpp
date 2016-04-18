#include "scene.hpp"
using namespace game;

Scene::Scene()
{
	debug("DEFAULT-constructor");
	description = "No description";
	currentPlayer = 0;
}

Scene::Scene(const Scene & s)
{
	debug("COPY-constructor");
	description = s.description;
	currentPlayer = s.currentPlayer;
}
Scene::Scene(std::string description_In)
{
	debug("SELF-constructor");
	description = description_In;
	currentPlayer = 0;

}

Scene::~Scene()
{
	debug("DESTRUCTOR");
}
Player * Scene::action()
{
	Player * tmp = NULL;

	if(currentPlayer >= player_vec.size())
	{
		currentPlayer = 0;
	}

	tmp = player_vec[currentPlayer];
	currentPlayer++;
	return tmp;
}

//----------------------------
//------ FUNCTIONALITY  ------
//----------------------------

void go(std::string s);
void pickup(std::string s);
void drop(std::string s);
Player * action();




//----------------------------
//------ 	PRINTS		------
//----------------------------
void Scene::printExits() const
{
	std::cout << "You see " << exits_map.size() << " exits." << std::endl;
	for(auto it = exits_map.begin(); it != exits_map.end(); ++it)
	{
		it->second->printDescription();
	}

}

void Scene::printItems() const
{
	for(auto it = item_vec.begin(); it != item_vec.end(); ++it)
	{
		(*it)->printDescription();
	}
}

void Scene::printPlayers() const
{
	for(auto it = player_vec.begin(); it != player_vec.end(); ++it)
	{
		auto p_p = *(it);
		p_p->printName();
	}
}
void Scene::printDescription() const
{
	std::cout << description << std::endl;
}



//----------------------------
//------ 	SETTERS		------
//----------------------------
void Scene::setItem(Item * i)
{
	item_vec.push_back(i);
}

void Scene::setExit(std::string name, Scene* scene_p)
{
	exits_map.insert(std::pair<std::string , Scene *>(name  , scene_p));
}
void Scene::setPlayer(Player * p)
{
	player_vec.push_back(p);
}




//----------------------------
//------ 	REMOVERS	------
//----------------------------
Scene * Scene::removeExit(std::string name)
{
	Scene * tmp_ptr = NULL;
	for(auto it = exits_map.begin(); it != exits_map.end(); ++it)
	{
		if(it->first == name)
		{
			tmp_ptr = it->second;
	 		exits_map.erase(name);
	 		return tmp_ptr;
		}
	}
	return tmp_ptr;
}


Item * Scene::removeItem(std::string item_name)
{
	Item * tmp = NULL;
	for(auto it = item_vec.begin(); it != item_vec.end(); ++it)
	{
		if((*it)->getName() == item_name)
		{
			tmp = (*it);
			item_vec.erase(it);
			return tmp;
		}
	}

	return tmp;
}


Player * Scene::removePlayer(std::string player_name)
{
	Player * tmp = NULL;
	for(auto it = player_vec.begin(); it != player_vec.end(); ++it)
	{
		if((*it)->getName() == player_name)
		{
			tmp = (*it);
			player_vec.erase(it);
			return tmp;
		}
	}
	return tmp;
}


//----------------------------
//------ 	GETTERS 	------
//----------------------------
Item * Scene::getItem(std::string item_name)
{
	Item * tmp = NULL;
	for(auto it = item_vec.begin(); it != item_vec.end(); ++it)
	{
		if((*it)->getName() == item_name)
		{
			tmp = (*it);
			return tmp;
		}
	}

	return tmp;	
}

Player * Scene::getPlayer(std::string name)
{
	Player * tmp = NULL;
	for(auto it = player_vec.begin(); it != player_vec.end(); ++it)
	{
		if((*it)->getName() == name)
		{
			tmp = (*it);
			return tmp;
		}
	}
	return tmp;
}

Scene * Scene::getExit(std::string name)
{
	Scene * tmp_ptr = NULL;
	for(auto it = exits_map.begin(); it != exits_map.end(); ++it)
	{
		if(it->first == name)
		{
			tmp_ptr = it->second;
	 		return tmp_ptr;
		}
	}
	return tmp_ptr;
}






