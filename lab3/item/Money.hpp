#ifndef MONEY_H
#define MONEY_H
#include "Item.hpp"


class Money : public Item
{
	public:
		Money()
		{
			the_weight = 1;
			the_price = 1;
			total_amount = 1;
		};
		Money(int amount)
		{
			the_weight = 1*amount;
			the_price = 1*amount;
			total_amount = 1*amount;
		}


		virtual std::string description() const override
		{return "Money, total amount: " + std::to_string(total_amount);}


	protected:
		int total_amount;

};



#endif