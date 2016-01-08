#ifndef PIRATE_H
#define PIRATE_H
#include "Character.hpp"
#include "Human.hpp"


class Pirate : public Human{

	public: 
	//		CONSTRUCTORS
	Pirate();
	Pirate(const Pirate & m);
	~Pirate();

	
	//		MEMBER FUNCTIONS
	virtual std::string name() const override;
	virtual std::string description() const override;
	virtual void attack(Character &) override;
	virtual void drop() override;
	virtual void action() override;
	virtual std::string talk(std::string s) override;
	virtual std::string attacked(int i) override;

	protected:
	//		ATTRIBUTES

};


#endif