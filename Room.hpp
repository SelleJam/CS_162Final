/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is the room class. It's basically a linked list of 
the space class. It's got functions for creating the grid, populating monsters,
and moving them each turn. Variable map sizes and danger levels can be implemented
though I didn't have time to put that into the menu function.
* ****************************************************************************/
#include "Tile.hpp"
#include "healingTile.hpp"
#include "Monster.hpp"
#include "spikeTile.hpp"

#ifndef ROOM_HPP
#define ROOM_HPP
class Creature;
class Monster;
class Room
{
protected:
	int yAxisLength;
	int xAxisLength;
	Space *origin;
	int dangerLevel;

public:
	Room();
	Room(int x, int y);
	void createRow(Space*);
	void createCol(Space*);
	void linkCol(Space*);
	Space* traverseCol(Space*, int);
	Space* traverseRow(Space*, int);
	void printRoom();
	Space* getOrigin();
	void populateMonsters();
	void setDangerLevel(int);
	bool moveMonsters();
	~Room();
};
#endif

