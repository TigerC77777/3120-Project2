#ifndef HEAPSORT_TPP
#define HEAPSORT_TPP

#include "heapSort.h"

template <typename T>
void HeapSortStrategy<T>::sort(std::vector<T>& vec)
{
	// First turn this vector into a heap
	for (int s = vec.size() / 2 - 1; s >= 0; s--)
		bubbleDown(vec, s, vec.size());

	for (int s = vec.size(); s > 0; s--)
	{
		// Swap the values
		T tempValue = vec[0];
		vec[0] = vec[s];
		vec[s] = tempValue;

		// Bubble down
		bubbleDown(vec, 0, s);
	}
}

template <typename T>
void HeapSortStrategy<T>::bubbleDown(std::vector<T>& vec, int localRoot, int size)
{
	bool done = false;
	while (!done)
	{
		int largest = localRoot;
		int leftChild = localRoot * 2 + 1;
		int rightChild = localRoot * 2 + 2;

		if (leftChild < size && vec[leftChild] > vec[largest])
			largest = leftChild;
		if (rightChild < size && vec[rightChild] > vec[largest])
			largest = rightChild;

		if (largest != localRoot)
		{
			T tempSwap = vec[largest];
			vec[largest] = vec[localRoot];
			vec[localRoot] = tempSwap;
			localRoot = largest;
		}
		else
			done = true;
	}
}

#endif