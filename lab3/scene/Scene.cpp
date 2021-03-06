#include "Scene.hpp"

Scene::Scene(){
	Scene* west_ptr = NULL;
	Scene* north_ptr = NULL;	
	Scene* east_ptr = NULL;	
	Scene* south_ptr = NULL;	
	environment.insert(std::pair<char, Scene*>('w', west_ptr));
	environment.insert(std::pair<char, Scene*>('n', north_ptr));
	environment.insert(std::pair<char, Scene*>('e', east_ptr));
	environment.insert(std::pair<char, Scene*>('s', south_ptr));	
}


void Scene::enter(const Character & c){
	std::cout << "A character enters the room" << std::endl;
	const Character * c_p = &c;
 	the_characters.push_back(c_p);
}

void Scene::leave(const Character& c){
	std::cout << "A characters leaves the room" << std::endl;
	// std::vector<Character>::iterator the_character = std::find(the_characters.begin(),the_characters.end(),c);
	// if(the_character != the_characters.end()){
	// 	the_characters.erase(the_character);
	// }		
}

void Scene::pick_up(const Item& obj){
	std::cout<< "Picks up an item" << std::endl;
	// std::vector<Item>::iterator the_obj= std::find(the_items.begin(), the_items.end(),obj);
	// if(the_obj != the_items.end()){
	// 	the_items.erase(the_obj);
	// }
}

void Scene::drop(const Item& obj){
	std::cout << "The item is dropped" << std::endl;
	const Item * obj_p = &obj;
	the_items.push_back(obj_p);
}

std::string Scene::directions() const{
	std::string s = "There are directions";
	return s;
}

Scene Scene::neighbor() const{
	
	Scene temp;
	return temp;
}

std::string Scene::description() const{
	return standard_description;
}


void Scene::alter_connections(const char& key, Scene& place){
	// auto the_pair = environment.find(key);
	// the_pair.second = place;

	environment.find(key)->second = &place;
	if(key == 'w'){
		place.environment.find('e')->second = this;
	}
	else if(key == 'e'){
		place.environment.find('w')->second = this;
	}
	else if(key == 'n'){
		place.environment.find('s')->second = this;
	}
	else if(key == 's'){
		place.environment.find('n')->second = this;
	}
	

}



const Scene Scene::get_connections(const char& key)const{
	return *environment.find(key)->second;
}

// Scene& Scene::operator=(const Scene& s){
// 	the_items = s.the_items;
// 	the_characters = s.the_characters;
// 	standard_description = s.standard_description;
// 	return *this;
// }