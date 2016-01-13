#include "Money.hpp"

Money::Money()
{
	the_weight = 1;
	the_price = 1;
	total_amount = 1;
};
Money::Money(int amount)
{
	the_weight = 1*amount;
	the_price = 1*amount;
	total_amount = 1*amount;
}