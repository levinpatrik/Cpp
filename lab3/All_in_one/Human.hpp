#ifndef HUMAN_H
#define HUMAN_H

#include "Character.hpp"


class Human : public Character{

	public:

		//		VIRTUAL FUNCTIONS
		virtual std::string type() const override {return "Human";}

	
	protected:
		//		ATTRIBUTES 


};


#endif
