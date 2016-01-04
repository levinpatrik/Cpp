#ifndef CRAB_H
#define CRAB_H

#include "Animal.hpp"
#include "Character.hpp"

class Crab : public Animal{

	public: 
		//		CONSTRUCTORS
		Crab();
		Crab(const Crab & m);
		~Crab();


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