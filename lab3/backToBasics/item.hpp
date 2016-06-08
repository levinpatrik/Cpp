#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iostream>


//TODO: Add setter functions
namespace game
{
class Item{

public:
	
	Item();
	Item(const Item &);
	Item(std::string description_In, std::string name_In, int price_In);
	Item(std::string description_In, std::string name_In, int price_In, int atk_In, int stamina_In);
	~Item();


	//Prints
	void printDescription();


	//Getters
	std::string getDescription() const;	
	std::string getName() const;
	int getPrice() const;
	int getAtk() const;
	int getStamina() const;

	//Setters
	void debug(std::string s)
	{
		std::cout << s << std::endl;
	}
protected:
	int price;
	int atk;
	int stamina;
	std::string name;
	std::string description;
};
}	//end namespace.

#endif