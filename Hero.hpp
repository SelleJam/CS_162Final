/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is the hero class. The hero is your main dude. 
Hero has an inventory and health. If health reaches 0 the game ends.
You can hold three bombs in your inventory.
* ****************************************************************************/
#include "Creature.hpp"
#include "Inventory.hpp"


#ifndef HERO_HPP
#define HERO_HPP
class Hero : Creature
{
private:
	int health = 10;
	Inventory inventory;
public:
	Hero();
	Hero(Space*);
	~Hero();
	void move(char);
	void attack(char);
	void takeDamage();
	Space* getLoc();
	int getHealth() { return health; }
	int getInv() { return inventory.bombCount(); }
	bool deadDude();

};
#endif

