#include "Space.hpp"
#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature
{
protected:
	Space *loc;
	
public:
	Creature();
	Creature(Space*);
	~Creature();

	

};
#endif

