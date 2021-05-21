#include "SelectionSort.h"

SelectionSort::SelectionSort()
{
	m_num_of_comparisons = 0;
	m_num_of_permutations = 0;
	m_name = "Сортировка выбором";
}

void SelectionSort::Sort(Array & arr)
{
	PrintName();
	int * oddRowArr = 0;
	int min = 0,
		minIndex = 0,
		size = 0;
	
	for (int row = 0; row < arr.GetArrRow() && arr.CountOddNumInRow(row) != 0; ++row) {
		size = arr.CountOddNumInRow(row);
		oddRowArr = new int[size];
		arr.OddRow(oddRowArr, row);
		min = oddRowArr[0];
		for (int i = 0; i < size - 1; ++i) {
			for (int j = i + 1; j < size; ++j) {
					if (oddRowArr[j] < min) {
						min = oddRowArr[j];
						minIndex = j;
						m_num_of_comparisons += 1;
					}
					else {
						m_num_of_comparisons += 1;
					}
			}
			if (minIndex != i) {
				swap(oddRowArr[i], oddRowArr[minIndex]);
				m_num_of_permutations += 1;
			}
			min = oddRowArr[i + 1];
			minIndex = i + 1;
		}
		arr.OddRowToArr(oddRowArr, size, row);
		delete oddRowArr;
	}
}
