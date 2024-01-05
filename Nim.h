#pragma once
#ifndef NIM_H
#define NIM_H

#include "Heap.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Nim
{
	/*Data member*/
	private:
		static array<Heap, 4> Heaps;
		bool isHeapsEmpty;

	public:
		//Constructor:
		explicit Nim();
		//Destructor:
		~Nim();

		//Get Function:
		const array<Heap, 4>& getHeapsList() const;

		//Output:
		void displayMainMenu();
		void displayGame();
		void displayGuide();
		void displayHeaps();

		//Calculates nim sum(nim sum is an addition of base 2 whitout carry):
		array<unsigned int, 4>& calculateNimSum(array<Heap,4> heapsList);


	private:
		//Decides Computer's move:
		void npcMove();

};
#endif // !NIM_H


