#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <vector>
#include "sortStrategy.h"

template <typename T>
class BubbleSortStrategy : public SortStrategy<T>
{
	public:
		BubbleSortStrategy() { }
		virtual void sort(std::vector<T>&) override;
		void print() const;
	//private:
}

#endif
#include "bubbleSort.tpp"