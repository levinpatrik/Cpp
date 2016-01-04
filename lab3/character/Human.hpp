#ifndef HUMAN_H
#define HUMAN_H

#include "Character.hpp"


class Human : public Character{

	public:
		//		PURE VIRTUAL
		virtual void attack(const Character &) = 0;
		virtual void drop(const Item &) = 0;
		virtual std::string talk(std::string s) = 0;

		//		MEMBER FUNCTIONS
		virtual std::string type() const override {return "Human";}

	
	protected:
		//		ATTRIBUTES 


};


#endif
