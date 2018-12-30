
#include "Inventory.hpp"


Inventory::Inventory()
{
	bombs = 0;
}


Inventory::~Inventory()
{
}

void Inventory::getBombs(Space* cur)
{
	if (cur->hasBombs())
	{
		if (bombs < 3)
		{
			bombs++;
			cur->removeBombs();
		}
	}
}

void Inventory::useBomb(Space *splode)
{
	if (bombs > 0)
	{


		bombs -= 1;
		if (splode->getNorth())
		{
			splode->getNorth()->killMonster();
			if (splode->getNorth()->getEast())
			{
				splode->getNorth()->getEast()->killMonster();
			}
			if (splode->getNorth()->getWest())
			{
				splode->getNorth()->getWest()->killMonster();
			}
		}
		if (splode->getSouth())
		{
			splode->getSouth()->killMonster();
			if (splode->getSouth()->getEast())
			{
				splode->getSouth()->getEast()->killMonster();
			}
			if (splode->getSouth()->getWest())
			{
				splode->getSouth()->getWest()->killMonster();
			}
		}
		if (splode->getEast())
		{
			splode->getEast()->killMonster();
			if (splode->getEast()->getNorth())
			{
				splode->getEast()->getNorth()->killMonster();
			}
			if (splode->getEast()->getSouth())
			{
				splode->getEast()->getSouth()->killMonster();
			}
		}
		if (splode->getWest())
		{
			splode->getWest()->killMonster();
			if (splode->getWest()->getNorth())
			{
				splode->getWest()->getNorth()->killMonster();
			}
			if (splode->getWest()->getSouth())
			{
				splode->getWest()->getSouth()->killMonster();
			}
		}
	}
}

int Inventory::bombCount()
{
	return bombs;
}
