#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
	m_num_of_comparisons = 0;
	m_num_of_permutations = 0;
	m_name = "Сортировка вставкой";
}

void InsertionSort::Sort(Array & arr)
{
	PrintName();
	int * oddRowArr = 0;
	int size = 0;
	int count = 0;
	for (int row = 0; row < arr.GetArrRow() && arr.CountOddNumInRow(row) != 0; ++row) {
		size = arr.CountOddNumInRow(row);
		oddRowArr = new int[size];
		arr.OddRow(oddRowArr, row);
		for (int i = 1; i < size; ++i) {
			for (int j = i; j > 0; --j) {
				if (oddRowArr[j - 1] > oddRowArr[j]) {
					swap(oddRowArr[j - 1], oddRowArr[j]);
					m_num_of_comparisons += 1;
					m_num_of_permutations += 1;
				}
				else {
					m_num_of_comparisons += 1;
				}
			}
		}
		arr.OddRowToArr(oddRowArr, size, row);
		delete oddRowArr;
	}
}
