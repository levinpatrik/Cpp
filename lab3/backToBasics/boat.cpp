#include "Boat.hpp"
using namespace game;

Boat::Boat()
{
	debug("DEFAULT-constructor");
	description = "No description";
	currentPlayer = 0;
}

Boat::Boat(const Boat & s)
{
	debug("COPY-constructor");
	description = s.description;
	currentPlayer = s.currentPlayer;
}
Boat::Boat(std::string description_In)
{
	debug("SELF-constructor");
	description = description_In;
	currentPlayer = 0;

}

Boat::~Boat()
{
	debug("DESTRUCTOR");
}
