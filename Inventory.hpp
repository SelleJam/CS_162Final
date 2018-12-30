/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is the inventory class. You can hold bombs in your 
inventory, and you pick them up off the ground. The splode to kill all 
surrounding monsters.
* ****************************************************************************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP


#include "Tile.hpp"
class Inventory
{
private:
	int bombs;
public:
	Inventory();
	~Inventory();

	void getBombs(Space*);
	void useBomb(Space*);
	int bombCount();
};

#endif // !INVENTORY_HPP