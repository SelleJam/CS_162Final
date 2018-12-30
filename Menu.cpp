
#include "Menu.hpp"
#include <iostream>
#include <limits>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

Menu::Menu()
{
}

int Menu::select()
{
	int choice;
	cout << "Enter a number to choose a combatant (0 to quit): \n";
	cout << "1: Vampire \n";
	cout << "2: Barbarian \n";
	cout << "3: Blue Men \n";
	cout << "4: Medusa \n";
	cout << "5: Harry Potter \n";
	cin >> choice;

	while (!cin || (choice < 0 && choice > 5))				//input is approved when integer 1 or 0
	{
		cout << "Enter a number to choose a combatant (0 to quit): \n";
		cout << "1: Vampire \n";
		cout << "2: Barbarian \n";
		cout << "3: Blue Men \n";
		cout << "4: Medusa \n";
		cout << "5: Harry Potter \n";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}

int Menu::playAgain()
{
	int choice;
	cout << "Enter 1 to play again! (3 to quit): ";
	cin >> choice;

	while (!cin || (choice != 1 && choice != 0))				//input is approved when integer 1 or 0
	{
		cout << "Enter 1 to play again (3 to quit): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}

int Menu::start()
{
	int choice;
	cout << "1) Play\n";
	cout << "2) Instructions\n";
	cout << "3) Quit\n";
	cin >> choice;

	while (!cin || (choice < 1 || choice > 3))				//input is approved when integer 1 thru 3
	{
		cout << "Enter 1 to start the program (3 to quit): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}
