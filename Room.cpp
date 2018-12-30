
#include "Room.hpp"
#include <iostream>


Room::Room()
{
}

/*******************************************************************************
* Constructor that makes a room of x and y dimension. 

* ****************************************************************************/
Room::Room(int x, int y)
{
	xAxisLength = x;
	yAxisLength = y;
	origin = nullptr;
	//std::cout << "Set origin\n";
	createRow(origin);
	//std::cout << "Created row\n";
	createCol(origin);
	//std::cout << "Created col\n";
	for (int i = 0; i < xAxisLength; i++)
	{
		linkCol(traverseRow(origin, i));
	}
	//std::cout << "Linked col\n";
	
}
/*******************************************************************************
* runs in the constructor first, creating the top row of the map

* ****************************************************************************/
void Room::createRow(Space *orig) //take an origin point and create a row.
{

	Space *ptr = new Tile();
	origin = ptr;
	for (int i = 0; i < xAxisLength-1; i++)
	{
		Space* next;
		
		if (rand() % 100 < 3)
		{
			next = new healingTile();
		}
		else if (rand() % 100 < 3)
		{
			next = new spikeTile();
		}
		else
		{
			next = new Tile();
		}
		
		ptr->setEast(next);
		next->setWest(ptr);
		ptr = next;
	}
	
}

/*******************************************************************************
* runs after the first row is created, making columns from each space in the row

* ****************************************************************************/
void Room::createCol(Space *orig)
{
	Space* x, *y;
	x = orig;
	y = orig;
	for (int i = 0; i < xAxisLength; i++)
	{
		y = traverseRow(orig, i);

		for (int h = 0; h < yAxisLength-1; h++)
		{
			Space* next;
			
			if (rand() % 100 < 3)
			{
				next = new healingTile();
			}
			else if (rand() % 100 < 10)
			{
				next = new spikeTile();
			}
			else
			{
				next = new Tile();
			}

			next->setNorth(y);
			//std::cout << "North Y= " << h << " X= " << i << "\n";
			y->setSouth(next);
			//std::cout << "South Y= " << h + 1 << " X= " << i << "\n";
			y = next;
			//std::cout << "Y= " << h << ", ";
			//std::cout << "X= " << i << "\n";
		}
		
		
		
	}
}

/*******************************************************************************
* Link up the columns, and now we have a grid!

* ****************************************************************************/

void Room::linkCol(Space *orig)
{
	
	for (int i = 0; i < yAxisLength; i++)
	{
		if (traverseRow(orig, 0)->getEast())
		{
			Space* lSpace;
			Space* rSpace;

			lSpace = traverseCol(orig, i);
			rSpace = traverseCol(traverseRow(orig, 1), i);

			lSpace->setEast(rSpace);
			rSpace->setWest(lSpace);


			//std::cout << "Linking columns at " << i << "\n";
		}
	}
}

/*******************************************************************************
* Start from an origin space and go y spaces up the column. Origin point
is passed to the function as parameter.

* ****************************************************************************/
Space * Room::traverseCol(Space* orig, int yCoord)
{

	Space* tmp;
	Space* y;
	y = orig;
	for (int i = 0; i < yCoord; i++)
	{
		tmp = y->getSouth();
		y = tmp;
	}

		return y;

}

/*******************************************************************************
* Start from an origin space and travel x spaces along the row of that space

* ****************************************************************************/
Space * Room::traverseRow(Space* orig, int xCoord)
{
	Space* tmp;
	Space* x;
	x = orig;
	if (xCoord == 0)
		return x;
	else {
		for (int i = 0; i < xCoord; i++)
		{
			tmp = x->getEast();
			x = tmp;
		}
	}
	return x;
}

/*******************************************************************************
* Prints the room, calling the polymorphic pringSpace() function. So fancy!

* ****************************************************************************/
void Room::printRoom()
{
	Space* tmp, *current;
	current = origin;
	int counter = 1;
	int moves = 0;
	while (current->getSouth())
	{
		while (current->getEast())
		{

			tmp = current->getEast();
			current->printSpace();
			current = tmp;
		}
		current->printSpace();

		current = traverseCol(origin, counter);
		counter++;
	}
	while (current->getEast())
	{

		tmp = current->getEast();
		current->printSpace();
		current = tmp;
	}
	current->printSpace();
}


Space* Room::getOrigin()
{
	return origin;
}

/*******************************************************************************
* Populates the map with monsters. Each space has a probability of generating
a monster determined by the danger level and size of the room.

* ****************************************************************************/
void Room::populateMonsters()
{
	
	Space* tmp, *current;
	current = origin;
	int counter = 1;
	while (current->getSouth())
	{
		while (current->getEast())
		{

			tmp = current->getEast();
			if (rand() % (xAxisLength * yAxisLength) < dangerLevel)
			{
				Monster* mon = new Monster(current);
				current->setMonster(mon);
				
			}
			current = tmp;
		}
		if (rand() % (xAxisLength * yAxisLength) < dangerLevel)
		{
			Monster* mon = new Monster(current);
			current->setMonster(mon);
			
		}

		current = traverseCol(origin, counter);
		counter++;
	}
	while (current->getEast())
	{

		tmp = current->getEast();
		if (rand() % (xAxisLength * yAxisLength) < dangerLevel)
		{
			Monster* mon = new Monster(current);
			current->setMonster(mon);
			
		}
		current = tmp;
	}
	if (rand() % (xAxisLength * yAxisLength) < dangerLevel)
	{
		Monster* mon = new Monster(current);
		current->setMonster(mon);
	}
}

void Room::setDangerLevel(int dang)
{
	dangerLevel = dang;
}

/*******************************************************************************
* This function both moves monsters and has a chance of generating bombs

* ****************************************************************************/

bool Room::moveMonsters()
{
	Space* tmp, *current;
	current = origin;
	int counter = 1;
	int moves = 0;
	while (current->getSouth())
	{
		while (current->getEast())
		{

			tmp = current->getEast();
			if (current->hasMonster())
			{
				current->getMonster()->move();
				moves++;
			}
			else if (rand() % 1000 <1)
			{
				current->setBombs();
			}
		
			current = tmp;
		}
		if (current->hasMonster())
		{
			current->getMonster()->move();
			moves++;
		}
		else if (rand() % 1000 < 1)
		{
			current->setBombs();
		}
		current = traverseCol(origin, counter);
		counter++;
	}
	while (current->getEast())
	{

		tmp = current->getEast();
		if (current->hasMonster())
		{
			current->getMonster()->move();
			moves++;
		}
		else if (rand() % 1000 < 1)
		{
			current->setBombs();
		}
		current = tmp;
	}
	if (current->hasMonster())
	{
		current->getMonster()->move();
		moves++;
	}
	else if (rand() % 1000 < 1)
	{
		current->setBombs();
	}

	if (moves > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}





Room::~Room()
{
}
