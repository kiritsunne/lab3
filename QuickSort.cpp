#include "QuickSort.h"

QuickSort::QuickSort()
{
	m_num_of_comparisons = 0;
	m_num_of_permutations = 0;
	m_name = "Быстрая сортировка";
}

void QuickSort::Sort(Array & arr)
{
	PrintName();
	int * oddRowArr = 0;
	int size = 0;
	
	for (int row = 0; row < arr.GetArrRow() && arr.CountOddNumInRow(row) != 0; ++row) {
		size = arr.CountOddNumInRow(row);
		oddRowArr = new int[size];
		arr.OddRow(oddRowArr, row);
		QuickSortFunc(oddRowArr, size);
		arr.OddRowToArr(oddRowArr, size, row);
		delete oddRowArr;
	}
}

void QuickSort::QuickSortFunc(int * arr, int size)
{
	int middle = arr[size/2],
		lSide = 0,
		rSide = size - 1;
	do {
		while (arr[lSide] < middle) { 
			lSide += 1;
			m_num_of_comparisons += 1;
		}
		while (arr[rSide] > middle) { 
			rSide -= 1;
			m_num_of_comparisons += 1;
		}
		if (lSide <= rSide) {
			swap(arr[lSide], arr[rSide]);
			m_num_of_permutations += 1;
			lSide += 1;
			rSide -= 1;
		}
	} while (lSide <= rSide);
	if (0 < rSide) QuickSortFunc(arr, rSide + 1);
	if (size > lSide) QuickSortFunc(&arr[lSide], size - lSide);
}
