#pragma once
#include "ISort.h"
class QuickSort: public ISort
{
public:
	QuickSort();
	void Sort(Array & arr);
	void QuickSortFunc(int * arr, int size);
};

