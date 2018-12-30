
#include "spikeTile.hpp"
#include <iostream>

spikeTile::spikeTile()
{
}


spikeTile::~spikeTile()
{
}

void spikeTile::setHero()
{
	flagHero = true;
}

void spikeTile::removeHero()
{
	flagHero = false;
}

bool spikeTile::hasHero()
{
	return flagHero;
}

void spikeTile::printSpace()
{
	if (flagHero)
		std::cout << "H";
	else if (flagMonster)
	{
		std::cout << "*";
	}
	else
	{
		std::cout << "^";
	}
	if (!this->getEast())
	{
		std::cout << "\n";
	}
}

void spikeTile::setMonster(Monster* mon)
{
	flagMonster = true;
	monster = mon;
}

void spikeTile::removeMonster()
{
	flagMonster = false;
	Monster *tmp = monster;
	monster = nullptr;
	delete monster;
}

Monster * spikeTile::getMonster()
{
	return monster;
}

void spikeTile::killMonster()
{
	if (this->hasMonster())
	{
		flagMonster = false;
		monster = nullptr;
		delete monster;
		std::cout << "Monster killed\n";
	}
}

bool spikeTile::hasMonster()
{
	if (flagMonster)
		return true;
	else
	{
		return false;
	}
}
