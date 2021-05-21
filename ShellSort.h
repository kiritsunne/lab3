#pragma once
#include "ISort.h"
class ShellSort :
	public ISort
{
public:
	ShellSort();
	void Sort(Array & arr);
};

