
#include "Monster.hpp"
#include <iostream>


Monster::Monster()
{
}

Monster::Monster(Space *location)
	: Creature(loc)
{
	loc = location;
	loc->setMonster(this);
}

void Monster::move()
{
	moved = false;
	if (loc)
	{


		int direction = std::rand() % 4;

		if (direction == 0 && loc->getNorth())
		{

			if (loc->getNorth()->hasMonster() == false)
			{

				loc->removeMonster();
				
				loc = loc->getNorth();
				loc->setMonster(this);

			}

		}


		if (direction == 1 && loc->getSouth())
		{

			if (loc->getSouth()->hasMonster() == false)
			{


				loc->removeMonster();
				
				loc = loc->getSouth();

				loc->setMonster(this);

			}
		}


		if (direction == 2 && loc->getEast())
		{

			if (loc->getEast()->hasMonster() == false)
			{


				loc->removeMonster();
				
				loc = loc->getEast();

				loc->setMonster(this);

			}
		}


		if (direction == 3 && loc->getWest())
		{

			if (loc->getWest()->hasMonster() == false)
			{

				loc->removeMonster();
				
				loc = loc->getWest();

				loc->setMonster(this);

			}
		}
	}
	else
	{

		delete this;
	}
}

void Monster::moveSpec(Space *l)
{
	moved = true;
	loc = l;
	loc->setMonster(this);

}


Monster::~Monster()
{
}
