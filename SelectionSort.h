#pragma once
#include "ISort.h"
class SelectionSort :
	public ISort
{
public:
	SelectionSort();
	void Sort(Array & arr);
};

