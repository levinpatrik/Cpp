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
	for(auto it = item_vec.begin(); it != item_vec.end(); ++it)
	{
		delete *it;
	}
}



//-------------------------------
//------ HELPER FUNCTIONS  ------
//-------------------------------

void Scene::sceneUpdate()
{
	for(auto it = player_vec.begin(); it != player_vec.end();)
	{
		if((*it)->getHp() <= 0)
		{

			auto & dead_inventory = (*it)->deathAction();
			for(auto it2 = dead_inventory.begin(); it2 != dead_inventory.end(); ++it2)
			{
				setItem(*it2);
			}
			dead_inventory.clear();
			removePlayer((*it)->getName());
		}
		else
		{
			++it;
		}
	}

	currentPlayer = 0;
	while(player_vec[currentPlayer]->getName().compare("Player") != 0)		//If its not Players turn
	{
		player_vec[currentPlayer]->attack(getPlayer("Player"));

		if(currentPlayer < (player_vec.size() - 1) && player_vec.size() > 0)
		{
			currentPlayer++;
		}
		else
		{
			currentPlayer = 0;
		}
	}


}


//----------------------------
//------ FUNCTIONALITY  ------
//----------------------------

Scene * Scene::go()
{
	printExits();
	std::cout << "Where would you like to go?" << std::endl;
	std::string direction;
	std::cin >> direction;
	std::cout << std::string( 100, '\n' );

	auto s_p = getExit(direction);
	auto player_name = player_vec[currentPlayer]->getName();
	auto player_p = getPlayer(player_name);
	if(s_p == NULL)
	{	
		std::cout << "You can not go there." << std::endl;
		return NULL;
	}
	else if(s_p != NULL && s_p->entryRequirments(player_p) == 1)
	{
		removePlayer(player_name);
		s_p->setPlayer(player_p);
		std::cout << "You just entered ";
		s_p->printDescription();
		std::cout << "." << std::endl;
		return s_p;
	}
	else
	{
		return NULL;	//player_p did not meet the requirments.
	}
}

void Scene::pickup()
{
	std::string item_name;
	printItems();
	std::cout << "What do you want to pick up?" << std::endl;
	std::cin >> item_name;
	auto player_p = player_vec[currentPlayer];
	auto item_p = getItem(item_name);
	if( item_p != NULL && player_p != NULL)
	{
		removeItem(item_name);
		player_p->setItem(item_p);
		sceneUpdate();
	}
}

void Scene::drop()
{
	auto player_p = player_vec[currentPlayer];	
	std::string item_name;
	player_p->printInventory();
	std::cout << "What do you want to drop?" << std::endl;
	std::cin >> item_name;

	auto item_p = player_p->getItem(item_name);
	if(item_p != NULL)
	{
		setItem(item_p);
		player_p->removeItem(item_name);
	}

}

void Scene::fight()
{
	if(player_vec.size() != 1)
	{
		printPlayers();
		std::cout << "Who do you want to fight? ";
		std::string player_name;
		std::cin >> player_name;
		if(player_name == "Player")
		{
			std::cout << "It would be stupid to fight yourself..." << std::endl;
			return;
		}
		auto player_attacking = player_vec[currentPlayer];
		auto player_attacked = getPlayer(player_name);
	if(player_attacking != NULL && player_attacked != NULL)
	{	
		player_attacking->attack(player_attacked);
		sceneUpdate();
	}
	else
	{
		std::cout << "There is no one named " << player_name << " to attack." << std::endl;
	}
	}

}



//----------------------------
//------ 	PRINTS		------
//----------------------------
void Scene::printExits() const
{
	if(exits_map.size() > 0)
	{
		std::cout << "You see " << exits_map.size() << " exits." << std::endl;
		for(auto it = exits_map.begin(); it != exits_map.end(); ++it)
		{
			it->second->printDescription();
			std::cout << " to the " << it->first << std::endl;
		}
	}
	else
	{
		std::cout << "There are no exits." << std::endl;
	}

}

void Scene::printItems() const
{
	if(item_vec.begin() != item_vec.end())
	{
		std::cout << "You look around and see " << std::endl;
		for(auto it = item_vec.begin(); it != item_vec.end(); ++it)
		{
			(*it)->printDescription();
		}
	}
	else
	{
		std::cout << "There are no items on the ground" << std::endl; 
	}		
}

void Scene::printPlayers() const
{
	if(player_vec.size() > 1)
	{
		std::cout << "The following creatures are within this zone:" << std::endl;
		for(auto it = player_vec.begin(); it != (player_vec.end()-1); ++it)
		{
			auto p_p = *(it);
			p_p->printName();	
		}
	}
	else{
		std::cout << "You are alone in the zone." << std::endl;
	}	
	// for(int i = 0; i <= (player_vec.size()-2); ++i)
	// {
	// 	player_vec[i]->printName();
	// }
}
void Scene::printDescription() const
{
	std::cout  << description;
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
	currentPlayer = player_vec.size() - 1;		//Make the entering player the "active" one
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
	for(auto it = item_vec.begin(); it != item_vec.end();)
	{
		if((*it)->getName() == item_name)
		{
			tmp = (*it);
			it = item_vec.erase(it);
			return tmp;
		}
		else 
		{
			it++;
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



// int Scene::getNumberOfPlayers()
// {
// 	return player_vec.size();
// }


