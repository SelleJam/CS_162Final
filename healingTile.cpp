
#include "healingTile.hpp"
#include <iostream>


healingTile::healingTile()
{
}


healingTile::~healingTile()
{
}

void healingTile::setHero()
{
	flagHero = true;
}

void healingTile::removeHero()
{
	flagHero = false;
}

bool healingTile::hasHero()
{
	return flagHero;
}

void healingTile::printSpace()
{
	if (flagHero)
		std::cout << "H";
	else if (flagMonster)
	{
		std::cout << "*";
	}
	else
	{
		std::cout << "+";
	}
	if (!this->getEast())
	{
		std::cout << "\n";
	}
}

void healingTile::setMonster(Monster* mon)
{
	//std::cout << "inside Healing tile\n";
	if (!mon->getLoc())
	{
		mon->getLoc()->removeMonster();
	}
	else if (mon->hasMoved())
	{
		mon->getLoc()->removeMonster();
		
	}
	else
	{


		if (this->getNorth())
		{
			if (this->getNorth()->hasMonster() == false)
			{


				mon->moveSpec(this->getNorth());
			}
		}


		if (this->getSouth())
		{
			if (this->getSouth()->hasMonster() == false)
			{


				mon->moveSpec(this->getSouth());
			}
		}


		if (this->getEast())
		{
			if (this->getEast()->hasMonster() == false)
			{


				mon->moveSpec(this->getEast());
			}
		}


		if (this->getWest())
		{
			if (this->getWest()->hasMonster() == false)
			{


				mon->moveSpec(this->getWest());
			}
		}
		else
		{
			mon->getLoc()->removeMonster();
			
			//std::cout << "monster deleted\n";
		}
		//std::cout << "leaving healing tile\n";
	}
}

void healingTile::removeMonster()
{
	
		Monster *tmp = monster;
		monster = nullptr;
		delete monster;
	
}

void healingTile::killMonster()
{
	if (this->hasMonster())
	{
		flagMonster = false;
		monster = nullptr;
		delete monster;
		std::cout << "Monster killed\n";
	}
}
