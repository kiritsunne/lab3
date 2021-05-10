#pragma once
#include "Array.h"
 class ISort
{
private:
	int m_num_of_comparisons;
	int m_num_of_permutations;
public:
	virtual void Sort(Array & arr) = 0;
};

