#ifndef MERGESORT_TPP
#define MERGESORT_TPP

#include "mergeSort.h"

template <typename T>
void MergeSortStrategy<T>::sort(std::vector<T>& vec)
{
	std::vector<T> workVec = vec;
	mergeSortSplit(vec, 0, vec.size(), workVec);
}

template <typename T>
void MergeSortStrategy<T>::mergeSortSplit(std::vector<T>& vec, int start, int end, std::vector<T>& workVec)
{
	// Stop the recursion if it is of size 1
	if (end - start <= 1)
		return;

	// Find a split point, recursively call function with split parts
	int split = (start + end) / 2;
	mergeSortSplit(vec, start, split, workVec);
	mergeSortSplit(vec, split, end, workVec);
	// Then merge the parts together while sorting it
	mergeSortMerge(workVec, start, split, end, vec);
}

template <typename T>
void MergeSortStrategy<T>::mergeSortMerge(std::vector<T>& workVec, int start, int split, int end, std::vector<T>& vec)
{
	int i = start;
	int j = split;

	// Iterate through the values in the merging splits
	for (int k = start; k < end; k++)
	{
		// if left split has values still AND (right split has no values OR current left value < current right value)
		if (i < split && (j >= end || vec[i] <= vec[j]))
		{
			// Put left split value in
			workVec[k] = vec[i];
			i++;
		}
		else
		{
			// Put right split value in
			workVec[k] = vec[j];
			j++;
		}
	}
}

#endif