#ifndef PLAYER_H
#define PLAYER_H
#include "Character.hpp"
#include "Human.hpp"

class Player : public Human{

public:
	Player();
	Player(const Player &);
	~Player();

	
	//		MEMBER FUNCTIONS
	virtual std::string name() const override;
	virtual std::string description() const override;
	virtual void attack(const Character &) override;
	virtual void drop(const Item &) override;
	virtual void action() override;
	virtual std::string talk(std::string s) override;

	void pick_up(const Item &);



protected:
	int money;

};


#endif

