#ifndef SORT_CONTEXT_H
#define SORT_CONTEXT_H

#include <vector>
template <typename T>
class SortContext
{
	public:
		SortContext(Sort<T>* s) : sortType(s);
		void setSort(Sort<T>* s) { sortType = s; }
		void sort(std::vector<T>& vec)
		{
			sortType->sort(vec);
		}
	private:
		Sort<T>* sortType;
}

#endif