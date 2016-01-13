#ifndef MONEY_H
#define MONEY_H
#include "Item.hpp"


class Money : public Item
{
	public:
		Money();
		Money(int amount);


		virtual std::string description() const override
		{return "Money, total amount: " + std::to_string(total_amount);}


	protected:
		int total_amount;

};



#endif