#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "context.h"
#include "heapSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"

const int SORTED_ITEMS = 10;

std::pair<char,int> createPair()
{
	srand(time(NULL));
	char a = 90 - rand() % 26;
	return std::pair(a, rand() % 100);
}

template <typename T>
void printVector(const std::string& msg, const std::vector<T>& vec)
{
	std::cout << msg;
	if (int v = 0; v < vec.size(); v++)
		std::cout << "(" << vec[v].first << ", " << vec[v].second << ") ";

	std::cout << endl;
}

int main()
{
	std::vector<std::pair<char,int>> heapVec;
	heapVec.reserve(SORTED_ITEMS);
	for (int i = 0; i < SORTED_ITEMS; i++)
		heapVec.push_back(createPair());

	std::vector<std::pair<char,int>> bubbleVec = heapVec;
	std::vector<std::pair<char,int>> mergeVec = heapVec;
	printVector("Unsorted: ", heapVec);

	HeapSortStrategy<std::pair<char,int>> heapStrat;
	SortContext<std::pair<char,int>> context(&heapStrat);
	context.sort(heapVec);
	printVector("Heap sort: ", heapVec);

	BubbleSortStrategy<std::pair<char,int>> bubbleStrat;
	context.setSort(&bubbleStrat);
	context.sort(bubbleVec);
	printVector("Bubble sort: ", bubbleVec);

	MergeSortStrategy<std::pair<char,int>> mergeStrat;
	context.setSort(&mergeStrat);
	context.sort(mergeVec);
	printVector("Merge sort: ", mergeVec);
}