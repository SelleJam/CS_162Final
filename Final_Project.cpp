/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is my final project. It's an HP lovecraft inspired game
full of tentacle monsters trying to kill you. There is a parent Creature class
with Hero and Monster derived classes. The abstract class is Space and there
are three derived classes, Tile, healingTile, and spikeTile.
* ****************************************************************************/
#include "Hero.hpp"
#include "Room.hpp"
#include "Monster.hpp"
#include "Menu.hpp"
#include <iostream>
#include <stdio.h>
#include <ctime>

int main()
{
	srand(time(NULL));
	Menu menu;
	int choice = menu.start();
	while (choice == 1 || choice == 2)
	{


		if (choice == 1)
		{


			Room room(30, 10);
			room.setDangerLevel(20);
			Hero dudeguy(room.getOrigin());
			room.populateMonsters();
			bool firstTurn = true;
			char input;
			bool endGameNoMon = false;
			bool endGameNoHealth = false;
			int counter = 0;
			while (firstTurn)
			{
				while (endGameNoMon == false && endGameNoHealth == false && counter < 500)
				{


					firstTurn = false;
					std::cout << "Health: " << dudeguy.getHealth() << " Bombs: " << dudeguy.getInv() << " Steps Remaining: " << 500-counter << "\n";
					room.printRoom();
					std::cin >> input;
					if (input == 'a' || input == 'w' || input == 's' || input == 'd')
					{
						dudeguy.move(input);
					}
					else if (input == 'j' || input == 'k' || input == 'l' || input == 'i' || 'o')
					{
						dudeguy.attack(input);
					}
						

					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					endGameNoMon = room.moveMonsters();
					
					if (dudeguy.getLoc()->hasMonster())
					{
						dudeguy.takeDamage();
					}
					endGameNoHealth = dudeguy.deadDude();
					counter++;
				}
			}
		}
		if (choice == 2)
		{
			std::cout << "Instructions: \n\n You awake in a marble room full of dark fog. \n As the fog lifts you see that you are surounded by mindless tentacle monsters.\n";
			std::cout << "You must fight your way out. Kill all the monsters to end the game!\n If your health drops to zero, you die!!! Spikes and monsters damage your health!\n\n\n\n";
			std::cout << "Controls:\n\n Use 'w' to move north, 's' to move south, 'a' to move east, and 'd' to move west.\n\n";
			std::cout << "Use 'i' to attack north, 'j' to attack west, 'l' to attack east,\n and 'k' to attack south, and 'o' to throw a bomb\n\n\n";
			std::cout << "Symbols:\n\n Monsters: * \n Hero: H (that's you!)\n Spikes: ^ \n Healing: + (stand here to regenerate)\n\n\n";

		}
		choice = menu.start();
	}
	//room.traverseRow(room.traverseCol(room.getOrigin(), 1), 10)->printSpace();
	
	return 0;
}

