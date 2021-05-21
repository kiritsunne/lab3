#pragma once
#include "ISort.h"
class BubbleSort :public ISort
{
public:
	BubbleSort();
	void Sort(Array & arr);
};

