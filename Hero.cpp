
#include "Hero.hpp"


Hero::Hero()
{

}

Hero::Hero(Space* start)
{
	
	loc = start;
	loc->setHero();
}

Hero::~Hero()
{
}

void Hero::move(char direction)
{
	if (direction == 'w')
	{
		if (loc->getNorth())
		{
			loc->removeHero();
			loc = this->loc->getNorth();
			loc->setHero();
			health += loc->heal();
		}
	}
	else if (direction == 's')
	{
		if (loc->getSouth())
		{
			loc->removeHero();
			loc = this->loc->getSouth();
			loc->setHero();
			health += loc->heal();
		}
	}
	else if (direction == 'd')
	{
		if (loc->getEast())
		{
			loc->removeHero();
			loc = this->loc->getEast();
			loc->setHero();
			health += loc->heal();
		}
	}
	else if (direction == 'a')
	{
		if (loc->getWest())
		{
			loc->removeHero();
			loc = this->loc->getWest();
			loc->setHero();
			health += loc->heal();
		}
	}
	if (loc->hasBombs())
	{
		inventory.getBombs(loc);
	}
	
}

void Hero::attack(char direction)
{
	if (direction == 'i')
	{
		if (loc->getNorth())
		{
			if (loc->getNorth()->hasMonster())
			{
				loc->getNorth()->killMonster();
				
			}
			
		}
	}
	else if (direction == 'k')
	{
		if (loc->getSouth())
		{
			if (loc->getSouth()->hasMonster())
			{
				loc->getSouth()->killMonster();

			}

		}
	}
	else if (direction == 'l')
	{
		if (loc->getEast())
		{
			if (loc->getEast()->hasMonster())
			{
				loc->getEast()->killMonster();

			}

		}
	}
	else if (direction == 'j')
	{
		if (loc->getWest())
		{
			if (loc->getWest()->hasMonster())
			{
				loc->getWest()->killMonster();

			}

		}
	}
	else if (direction == 'o')
	{
		inventory.useBomb(loc);
	}
	health += loc->heal();
}

void Hero::takeDamage()
{
	health -= 1;
}

Space * Hero::getLoc()
{
	return loc;
}

bool Hero::deadDude()
{
	if (health <= 0)
		return true;
	return false;
}

