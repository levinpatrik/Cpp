#ifndef APE_H
#define APE_H

#include "Animal.hpp"
#include "Character.hpp"


class Ape : public Animal{

	public: 
		//		CONSTRUCTORS
		Ape();
		Ape(const Ape & m);
		~Ape();


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