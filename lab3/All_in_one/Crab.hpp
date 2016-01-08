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
		virtual void attack(Character &) override;
		virtual void drop() override;
		virtual void action() override;
		virtual std::string attacked(int i) override {return "AJ";}

	
	protected:
		//		ATTRIBUTES
		
};






#endif