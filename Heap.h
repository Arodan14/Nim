#pragma once
#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<string>
#include<array>
#include<sstream>

class Heap
{
	//Data members:
	private:
		unsigned int heapSize;
		std::array<unsigned int, 4> binaryHeap;
		std::array<std::string, 7> heap;//array that contains the number of token in the heap according to its size
		bool isHeapEmpty;

	//Member functions:
	public:
		//Constructor
		explicit Heap(unsigned int heapSize = 0);//default can initiate a heap object whitout arguments needed
		//Destructor
		~Heap();

		//Set functions
		void setHeapSize(unsigned int heapSize);
		void setIsHeapEmpty();
		//Get functions
		unsigned int getHeapSize() const;
		const std::array<unsigned int, 4>& getBinaryHeap() const;
		bool getisHeapEmpty() const;
		//convert heap array to a string
		std::string heapToString() const;

		//Convert to binary:
		std::array<unsigned int, 4>& decimalToBinary(unsigned int decimal);
		
		void displayBinary() const;
		/*Utility functions*/
		private:
			void setBinaryHeap();//sets the binary value of the heap size
			void setHeap();//sets the heap array according to the size

};

#endif // !HEAP_H

