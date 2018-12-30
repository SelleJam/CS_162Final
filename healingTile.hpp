/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is the healing tile derived class. It's a tile
that can hold heros and monsters, bombs can't spawn, and this tile heals you
each turn you stand on it.
* ****************************************************************************/

#ifndef HEALINGTILE_HPP
#define HEALINGTIME_HPP


#include "Space.hpp"
#include "Monster.hpp"


class healingTile :
	public Space
{
private:
	bool flagHero;
	
	bool flagMonster;
	Monster *monster;
	
	
	
public:
	healingTile();
	~healingTile();
	void setHero();
	void removeHero();
	bool hasHero();
	void printSpace();
	void setMonster(Monster*);
	void removeMonster();
	void killMonster();
	Monster* getMonster() { return monster; }
	
	bool hasMonster() { return flagMonster; }
	int heal() { return 1; }
	

	
};
#endif // !HEALINGTILE_HPP
