#include "Nim.h"

#include<cstdlib>
#include<time.h>

//Instantiation of heap class objects: 
Heap heap_1(1);
Heap heap_2(3);
Heap heap_3(5);
Heap heap_4(7);

//Initializes the static data member heaps
array<Heap, 4> Nim::Heaps{
	heap_1,
	heap_2,
	heap_3,
	heap_4
};

//Constructor
Nim::Nim()
{
	displayMainMenu();
}
//Destructor:
Nim::~Nim()
{

}

//Get Function:
const array<Heap, 4>& Nim::getHeapsList() const
{
	return Heaps;
}

//Output:
void Nim::displayMainMenu()
{
	unsigned int mainMenuChoice{ 0 };
	unsigned int turnChoice{ 0 };

	while (mainMenuChoice != 3)
	{
		cout << setw(2) << "" << setw(55) << setfill('-') << "" << " NIM " << setw(58) << setfill('-') << "" << setfill(' ') << endl;
		cout << endl;
		cout << setw(2) << "" << "1. Start game\n"
			<< setw(2) << "" << "2. Guide\n"
			<< setw(2) << "" << "3. Exit" << endl;

		cout << "\n>> ";
		cin >> mainMenuChoice;

		switch (mainMenuChoice)
		{
		//Start Game
		case 1:
			system("cls");
			displayGame();
			system("cls");
			
			break;
	    //Guide
		case 2:
			system("cls");
			displayGuide();
			system("cls");
			displayHeaps();
			cout << "pick a row:" << endl;
			cin >> turnChoice;
			system("cls");

			break;
		//Exit
		case 3:
			break;
		default:
			system("cls");
			cerr << "Invalid argument!" << endl;
			mainMenuChoice = 0;
			break;
		}
	}
}
void Nim::displayGame()
{
	string player_1;
	string player_2;
	string currentPlayer;

	int turnChoice{ 1 };

	while (turnChoice != -1)
	{
		//prompt user to choose his turn
		cout << " Choose your turn:\n\n"
			<< setw(3) << "" << "1.Player 1\n"
			<< setw(3) << "" << "2.Player 2\n"
			<< setw(3) << "" << "3.Exit" << endl;

		cout << "\n>>";
		cin >> turnChoice;
		
		switch (turnChoice)
		{	
			//Player 1:
			case 1:
				player_1 = "Human";
				player_2 = "Npc";
				break;
			//Player 2:
			case 2:
				player_1 = "Npc";
				player_2 = "Human";
				break;
			//Exit
			case 3:
				turnChoice = -1;
				system("cls");
			default:
				break;
		}
	}

}
void Nim::displayGuide()
{
	char mainMenu{ 'x' };

	while (mainMenu != '\n')
	{
		cout << setw(2) << "" << setw(54) << setfill('-') << "" << " GUIDE " << setw(57) << setfill('-') << "" << setfill(' ') << endl;
		cout << endl;

		cout << "* The traditional Nim-game (aka Marienbad-game) consists of four rows of 1, 3, 5 and 7 matchsticks\n (or any other objects).\n"
			 << "\n* Two players take any number of matchsticks from one row alternately. The one, who takes the last matchstick loses."
			<< endl;

		cout << endl;

		cout << "\n\n--> Press \'Enter key\' to return to main menu.";
		cin.ignore();
		cin.get(mainMenu);
	}
}
void Nim::displayHeaps()
{
	unsigned int count{ 1 };
	for (Heap heap : Heaps)
	{
		cout << setw(2) << "" << count << "." << setw(10) << "" << heap.heapToString() << endl;
		cout << endl;
		++count;
	}
}

//Calculates nim sum(nim sum is an addition of base 2 whitout carry):
array<unsigned int, 4>& Nim::calculateNimSum(array<Heap, 4> heapsList)
{
	array<unsigned int, 4> nimSum{ 0 };

	for (Heap& heap : heapsList)
	{
		for (size_t index{ 3 }; index >= 0; --index)
		{
			nimSum[index] += heap.getBinaryHeap()[index];

			if (index == 0)
			{
				break;
			}
		}
	}

	for (size_t index{ 0 }; index < nimSum.size(); ++index)
	{
		if ((nimSum[index] > 1) && ((nimSum[index] % 2) == 0))
		{
			nimSum[index] = 0;
		}
		if ((nimSum[index] > 1) && ((nimSum[index] % 2) != 0))
		{
			nimSum[index] = 1;
		}
	}

	return nimSum;
}

//Decides Computer's move:
void Nim::npcMove()
{
	//randomize the seed:
	srand(time(0));

	array<unsigned int, 4> nimSum = calculateNimSum(Heaps);

	size_t heapPicker = rand() % 3;
	
	unsigned int heapSize = 0;
	unsigned int newHeapSize = 0;


	bool isNimSumZero{ true };

	//checks if wheter the nimSum is zero or not:
	for (unsigned int bit : nimSum)
	{
		if (bit == 1)
		{
			isNimSumZero = false;
			break;
		}
	}
	
	/*
		If the nimSum equals zero the npc will make a random move by
		removing one or more tokens from a random heap while the heap is notEmpty 	
	*/
	if (isNimSumZero)
	{
		//finds a random nonempty heap
		while (Heaps.at(heapPicker).getisHeapEmpty())
		{
			heapPicker = rand() % 3;
		}

		cout << "\n HeapPicker: " << heapPicker;
		heapSize = Heaps.at(heapPicker).getHeapSize();
		newHeapSize = 1 + rand() % heapSize;
		Heaps.at(heapPicker).setHeapSize(heapSize - newHeapSize);

		cout << "\nHeap at: " << heapPicker << "\n" << "size: " << Heaps.at(heapPicker).getHeapSize() << endl;
	}

	else
	{

	}
}