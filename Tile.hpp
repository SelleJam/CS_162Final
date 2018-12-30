/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is the "regular" derived class. It's a tile
that can hold heros and monsters, bombs can spawn, which can be picked up and used. 
* ****************************************************************************/
#ifndef TILE_HPP
#define TILE_HPP


#include "Space.hpp"


class Tile :
	public Space
{
private:
	bool flagHero;
	bool flagMonster;
	bool flagBombs;
	Monster *monster;
	
public:
	Tile();
	~Tile();
	
	void setHero();
	void removeHero();
	void setMonster(Monster*);
	void removeMonster();
	bool hasMonster();
	bool hasHero();
	void printSpace();
	void killMonster();
	bool hasBombs();
	void setBombs();
	void removeBombs();
	Monster* getMonster();
};

#endif // !TILE_HPP