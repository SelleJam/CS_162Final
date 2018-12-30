
#include "Space.hpp"
#include <iostream>


Space::Space()
{
	North = nullptr;
	South = nullptr;
	East = nullptr;
	West = nullptr;
}

Space::Space(Space *n, Space *s, Space *e, Space *w)
{
	North = n;
	South = s;
	East = e;
	West = w;
}


Space::~Space()
{
}

void Space::setNorth(Space *n)
{
	North = n;
	//std::cout << "North Set\n";
}

void Space::setSouth(Space *s)
{
	South = s;
	//std::cout << "South Set\n";
}

void Space::setEast(Space *e)
{
	East = e;
	//std::cout << "East set\n";
}

void Space::setWest(Space *w)
{
	West = w;
	//std::cout << "West set\n";
}

Space * Space::getNorth()
{
	return North;
}

Space * Space::getSouth()
{
	return South;
}

Space * Space::getEast()
{
	return East;
}

Space * Space::getWest()
{
	return West;
}


