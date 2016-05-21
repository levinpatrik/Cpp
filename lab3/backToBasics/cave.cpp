#include "cave.hpp"
using namespace game;

Cave::Cave()
{
	debug("DEFAULT-constructor");
	description = "No description";
	currentPlayer = 0;
}

Cave::Cave(const Cave & s)
{
	debug("COPY-constructor");
	description = s.description;
	currentPlayer = s.currentPlayer;
}
Cave::Cave(std::string description_In)
{
	debug("SELF-constructor");
	description = description_In;
	currentPlayer = 0;

}

Cave::~Cave()
{
	debug("DESTRUCTOR");
}
