#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <vector>
#include "sortStrategy.h"

template <typename T>
class HeapSortStrategy : public SortStrategy<T>
{
	public:
		HeapSortStrategy() { }
		virtual void sort(std::vector<T>&) override;
		void print() const;
	private:
		void bubbleDown(std::vector<T>&, int, int)
}

#endif
#include "heapSort.tpp"