#include <iostream>
#include <array>
#include <string>
#include <random>
#include <Windows.h>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"

std::string title = R"(   _____    __________                            .__  .__ __              ________                       
  /  _  \   \______   \ ____   ____  __ __   ____ |  | |__|  | __ ____    /  _____/_____    _____   ____  
 /  /_\  \   |       _//  _ \ / ___\|  |  \_/ __ \|  | |  |  |/ // __ \  /   \  ___\__  \  /     \_/ __ \ 
/    |    \  |    |   (  <_> ) /_/  >  |  /\  ___/|  |_|  |    <\  ___/  \    \_\  \/ __ \|  Y Y  \  ___/ 
\____|__  /  |____|_  /\____/\___  /|____/  \___  >____/__|__|_ \\___  >  \______  (____  /__|_|  /\___  >
        \/          \/      /_____/             \/             \/    \/          \/     \/      \/     \/ )";

std::string options = R"(
1. Play
2. How to play
3. Exit
)";

std::string instructions = R"(
 _____             _             _     
/  __ \           | |           | |    
| /  \/ ___  _ __ | |_ _ __ ___ | |___ 
| |    / _ \| '_ \| __| '__/ _ \| / __|
| \__/\ (_) | | | | |_| | | (_) | \__ \
 \____/\___/|_| |_|\__|_|  \___/|_|___/                                                                             
 =====================================

w = Move up
a = Move left
s = Move right
d = Move down
i = Check inventory
q = Quit game

 _____             _ 
|  __ \           | |
| |  \/ ___   __ _| |
| | __ / _ \ / _` | |
| |_\ \ (_) | (_| | |
 \____/\___/ \__,_|_|
 ====================

Collect all the items and reach each room's door without being defeated by the enemies!                   
                     


)";

void PrintTitle() {	std::cout << title << '\n'; }
void PrintMenuOptions() { std::cout << options << '\n'; }
void PrintInstructions() { std::cout << instructions << '\n'; }

int main()
{
	const int ColumnSize = 100;
	const int RowSize = 20;

	Player player;
	Grid grid(RowSize, ColumnSize, &player);

	// Set the player reference for the Enemy class.
	
	bool isGameRunning{ false };
	bool isMenuRunning{ true };

	// Print the title screen header.
	PrintTitle();

	// Manage the main menu.
	while (isMenuRunning) 
	{
		PrintMenuOptions();

		char menuChoice;
		std::cin >> menuChoice;

		switch (menuChoice) 
		{
		case '1':
			system("cls");
			isMenuRunning = false;
			isGameRunning = true; 
			break;
		case '2':
			PrintInstructions();
			break;
		case '3':
			return 0;
		default:
			//std::cout << "The entered option was invalid, try again.\n";
			system("cls");
			PrintTitle();			
			break;
		}
	}

	while (isGameRunning)
	{
		system("cls");
		grid.print_dungeon();

		if (player.IsDamaged()) {
			std::cout << "You were hit for " << player.GetLastDamageAmount() << '\n'; 
		}

		if (player.GetHealth() <= 0)
		{ 
			std::cout << "You are dead!";
			isGameRunning = false;
			break;
		}

		char ch;
		std::cin >> ch;

		switch (ch)
		{
		case 'w':
			grid.moveUp();
			break;
		case 'a':
			grid.moveLeft();
			break;
		case 's':
			grid.moveDown();
			break;
		case 'd':
			grid.moveRight();
			break;
		case 'q':
			isGameRunning = false;
			break;
		case 'c':
			grid.clearTreasure();
			break;
		case 'i':
			grid.checkInventory();
			break;
		default:
			std::cout << ch << " is not a valid command\n";
		}

		grid.checkForTreasure();
		
		if (grid.checkForExit() && grid.getRemainingTreasureCount() == 0)
		{
			grid.create_new_dungeon();
		}
	}

	return 0;
}