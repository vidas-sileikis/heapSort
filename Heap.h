#include <vector>
template<typename T>
class Heap
{
public:
	Heap();
	Heap(const T elements[], int arraySize);
	void remove(); //Remove the root from the heap and maintain the heap property
	void add(const T& element); //Insert element into the heap and maintain the heap property
	int getSize() const; //Get the number of element in the heap
	void heapSort(); //to sort the heap
	void printVector(); //Print vector values
	void maxHeap(int rootIndex, int heapSize); //build a maxHeap
private:
	std::vector<T> v;
};
