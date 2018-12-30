#include "Creature.hpp"
#include <random>
#ifndef MONSTER_HPP
#define MONSTER_HPP
class Monster :
	protected Creature
{
private:
	bool moved;
public:
	Monster();
	Monster(Space*);
	void move();
	void moveSpec(Space*);
	Space* getLoc() { return loc; }
	bool hasMoved() { return moved; }

	~Monster();
};
#endif

