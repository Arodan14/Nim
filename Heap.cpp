#include "Heap.h"

//Constructor
Heap::Heap(unsigned int heapSize)
{
	setHeapSize(heapSize);
	setBinaryHeap();
	setHeap();
	setIsHeapEmpty();
}//default can initiate a heap object whitout arguments needed
//Destructor
Heap::~Heap()
{

}

//Set functions
void Heap::setHeapSize(unsigned int heapSize)
{
	this->heapSize = heapSize;
	setHeap();
}
void Heap::setIsHeapEmpty()
{
	for (unsigned int bit : binaryHeap)
	{
		if(bit == 1)
		{
			isHeapEmpty = false;
			break;
		}
		else
		{
			isHeapEmpty = true;
		}
	}
}
//Get functions
unsigned int Heap::getHeapSize() const
{
	return heapSize;
}
const std::array<unsigned int, 4>& Heap::getBinaryHeap() const
{
	return binaryHeap;
}
bool Heap::getisHeapEmpty() const
{
	return isHeapEmpty;
}

//Ouput heap
std::string Heap::heapToString() const
{
	std::ostringstream output;

	for (std::string token : heap)
	{
		output << token << " ";
	}

	return output.str();
}

//Convert to binary:
std::array<unsigned int, 4>& Heap::decimalToBinary(unsigned int decimal)
{
	unsigned int quotient{ decimal };
	unsigned int remainder{ decimal % 2};

	std::array<unsigned int, 4> binary{0};


	for (size_t index{ 3 }; index >= 0 ; --index)
	{
		remainder = quotient % 2;
		quotient = quotient / 2;
		
		binary[index] = remainder;

				if (index == 0)
				{
					break;
				}
	}

	return binary;
}

void Heap::displayBinary() const
{
	std::cout << "heap size in binary:\n";
	std::cout << heapSize << std::endl;
	for (unsigned int bit : binaryHeap)
	{
		std::cout << bit;
	}

	std::cout << std::endl;
}

/*Utility functions*/
void Heap::setBinaryHeap()
{
	for (size_t index{0} ; index < binaryHeap.size() ; ++index)
	{
		binaryHeap[index] = decimalToBinary(heapSize)[index];
	}
}
void Heap::setHeap()
{
	const size_t middle{ 3 };//the highest heap size in the traditional nim game is 7 so 3 is the middle of the heap array;
	const std::string token{ "|" };
	const std::string space{ " " };

	//Checks the heapsize value and set the heap array accordingly
	switch (heapSize)
	{
		case 0:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
					heap[index] = space;	
			}
			break;
		case 1:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
				if (index == middle)
				{
					heap[index] = token;
				}
				else
				{
					heap[index] = space;
				}
			}
			break;
		case 2:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
				if (index == middle || index == 4 )
				{
					heap[index] = token;
				}
				else
				{
					heap[index] = space;
				}
			}
			break;
		case 3:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
				if ((index >= 2) && (index <= 4))
				{
					heap[index] = token;
				}
				else
				{
					heap[index] = space;
				}
			}
			break;
		case 4:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
				if ((index >= 2) && (index <= 5))
				{
					heap[index] = token;
				}
				else
				{
					heap[index] = space;
				}
			}
			break;
		case 5:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
				if ((index >= 1) && (index <= 5))
				{
					heap[index] = token;
				}
				else
				{
					heap[index] = space;
				}
			}
			break;
		case 6:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
				if ((index >= 1) && (index <= 6))
				{
					heap[index] = token;
				}
				else
				{
					heap[index] = space;
				}
			}
			break;
		case 7:
			for (size_t index{ 0 }; index < heap.size(); ++index)
			{
					heap[index] = token;
			}
			break;
		default:
			break;
	}
}//sets the heap array according to the size