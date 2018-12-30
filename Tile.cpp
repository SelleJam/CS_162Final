
#include "Tile.hpp"
#include <iostream>


Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::setHero()
{
	flagHero = true;
	
}

void Tile::removeHero()
{
	flagHero = false;
	
}

void Tile::setMonster(Monster* mon)
{
	flagMonster = true;
	monster = mon;
}

void Tile::removeMonster()
{
	flagMonster = false;
	Monster *tmp = monster;
	monster = nullptr;
	delete monster;
}

bool Tile::hasMonster()
{
	if (flagMonster)
		return true;
	else
	{
		return false;
	}
}

bool Tile::hasHero()
{
	return flagHero;
}

void Tile::printSpace()
{
	if (flagHero)
		std::cout << "H";
	else if (flagMonster)
		std::cout << "*";
	else if (flagBombs)
	{
		std::cout << "O";
	}
	else
	{
		std::cout << " ";
	}
	if (!this->getEast())
	{
		std::cout << "\n";
	}
}

void Tile::killMonster()
{
	if (this->hasMonster())
	{
		flagMonster = false;
		monster = nullptr;
		delete monster;
		std::cout << "Monster killed\n";
	}
}

bool Tile::hasBombs()
{
	return flagBombs;
}

void Tile::setBombs()
{
	flagBombs = true;
}

void Tile::removeBombs()
{
	flagBombs = false;
}

Monster * Tile::getMonster()
{
	return monster;
}
