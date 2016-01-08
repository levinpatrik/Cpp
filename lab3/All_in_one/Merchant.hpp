#ifndef MERCHANT_H
#define MERCHANT_H
#include "Character.hpp"
#include "Human.hpp"


class Merchant : public Human{

public: 
	//		CONSTRUCTORS
	Merchant();
	Merchant(const Merchant & m);
	~Merchant();

	//		MEMBER FUNCTIONS
	virtual std::string name() const override;
	virtual std::string description() const override;
	virtual void attack(Character &) override;
	virtual void drop() override;
	virtual void action() override;
	virtual std::string talk(std::string s) override;
	virtual std::string attacked(int i) override {return "AJ";}

protected:
	//		ATTRIBUTES

};


#endif