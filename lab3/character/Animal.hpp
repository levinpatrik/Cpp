#ifndef ANIMAL_H
#define ANIMAL_H

#include "Character.hpp"


class Animal : public Character{

	public:
		//		PURE VIRTUAL
		virtual void attack(const Character &) = 0;
		virtual void drop(const Item &) = 0;

		//		MEMBER FUNCTIONS
		virtual std::string type() const override {return "Animal";}
	
	protected:
		//		ATTRIBUTES 


};


#endif
