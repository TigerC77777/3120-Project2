#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>
#include "sortStrategy.h"

template <typename T>
class MergeSortStrategy : public SortStrategy<T>
{
	public:
		MergeSortStrategy() { }
		virtual void sort(std::vector<T>&) override;
		void print() const;
	private:
		void mergeSortSplit(std::vector<T>&, int, int, std::vector<T>&);
		void mergeSortMerge(std::vector<T>&, int, int, int, std::vector<T>&);
}

#endif
#include "mergeSort.tpp"