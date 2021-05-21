#pragma once
#include "ISort.h"
class InsertionSort :
	public ISort
{
public:
	InsertionSort();
	void Sort(Array & arr);
};

