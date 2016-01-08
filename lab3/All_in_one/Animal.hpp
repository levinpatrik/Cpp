#ifndef ANIMAL_H
#define ANIMAL_H

#include "Character.hpp"


class Animal : public Character{

	public:
		//		MEMBER FUNCTIONS
		virtual std::string type() const override {return "Animal";}
	
	protected:
		//		ATTRIBUTES 


};


#endif
