#include <iostream>
#include "Heap.h"
using namespace std;

template<typename T>
Heap<T>::Heap()
{

}
template<typename T>
Heap<T>::Heap(const T elements[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		v.push_back(elements[i]); //Push each element onto the back of the vector
	}
}
template<typename T>
void Heap<T>::maxHeap(int rootIndex, int heapSize)
{
	while (heapSize > rootIndex) {
		int originalRoot = rootIndex;
		if ((2 * originalRoot) + 1 < heapSize) //Make sure left child exists
		{
			if (v[(2 * originalRoot) + 1] >= v[rootIndex]) //If left child value is greater than root value
			{
				rootIndex = (2 * originalRoot) + 1; //Set root Index as left child
			}
		}
		if ((2 * originalRoot) + 2 < heapSize) //Make sure right child exists
		{

			if (v[(2 * originalRoot) + 2] >= v[rootIndex]) //If right child value is greater than root value
			{
				rootIndex = (2 * originalRoot) + 2; //Set root index as right child
			}
		}

		if (rootIndex != originalRoot) //If rootIndex changes then we swap values with originalRoot
		{
			swap(v[originalRoot], v[rootIndex]);
		}
		else { //If rootIndex does not change then we are sorted
			
			break; //So we break out of while loop
		}
	}
}
template<typename T>
void Heap<T>::remove() //Remove the root from the heap and maintain the heap property
{
	for (int index = getSize() - 1; index >= 0; index--) {
		swap(v[0], v[index]); //Move the last node to replace the current node
		maxHeap(0, index); //Maintain heap property
	}
}
template<typename T>
void Heap<T>::add(const T &element) //Insert element into the heap and maintain the heap property
{
	v.push_back(element); //Insert element into the heap
	maxHeap(0, getSize()); //Maintain the heap property
}


template<typename T>
int Heap<T>::getSize() const //Get the number of element in the heap
{
	return v.size();
}


template <typename T>
void Heap<T>::heapSort() //Sort the elements in the heap
{
	int arraySize = getSize();
	for (int index = arraySize / 2 - 1; index >= 0; index--)
	{
		maxHeap(index, arraySize);
	}
	remove();
}

template<typename T>
void Heap<T>::printVector() //Print vector values
{
	for (int i = 0; i < getSize(); i++)
	{
		cout << v[i] << " ";
	}
}


