#ifndef CRAB_H
#define CRAB_H

#include "Animal.hpp"

class Crab : public Animal{

	public: 
		
		//		MEMBER FUNCTIONS
		virtual std::string name() const override;
		virtual std::string description() const override;
		
		virtual void attack(const Character &) override;
		virtual void drop(const Item &) override;
		
		virtual void action() override;
	
	protected:
		//		ATTRIBUTES
		

};

#endif