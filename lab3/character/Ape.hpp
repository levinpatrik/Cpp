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
		virtual void attack(const Character &) override;
		virtual void drop(const Item &) override;
		virtual void action() override;
	
	protected:
		//		ATTRIBUTES
		
};






#endif