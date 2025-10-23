#ifndef BUBBLESORT_TPP
#define BUBBLESORT_TPP

#include "bubbleSort.h"

template <typename T>
void BubbleSortStrategy<T>::sort(std::vector<T>& vec)
{
	int stoppingPoint = vec.size() - 2;
	if (stoppingPoint <= 0)
		return;

	bool done = false;
	while (!done)
	{
		done = true;
		for (int i = 0; i <= stoppingPoint; i++)
		{
			if (vec[i] > vec[i + 1])
			{
				T temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
				done = false;
			}
		}
		stoppingPoint--;
	}
}

#endif