/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is the spiked tile derived class. It's a tile
that can hold heros and monsters, bombs can't spawn, and it damages the
hero when he moves on the spikes (but not the monsters).
* ****************************************************************************/

#ifndef SPIKETILE_HPP
#define SPIKETIME_HPP


#include "Space.hpp"
#include "Monster.hpp"
class spikeTile :
	public Space
{
private:
	bool flagHero;
	bool flagMonster;
	Monster *monster;

public:
	spikeTile();
	~spikeTile();

	void setHero();
	void removeHero();
	bool hasHero();
	void printSpace();
	void setMonster(Monster*);
	void removeMonster();
	bool hasMonster();
	Monster* getMonster();
	void killMonster();

	
	int heal() { return -1; }
};

#endif // !SPIKETILE_HPP