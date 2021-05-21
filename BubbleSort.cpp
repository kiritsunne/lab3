#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
	m_num_of_comparisons = 0;
	m_num_of_permutations = 0;
	m_name = "Сортировка пузырьком";
}

void BubbleSort::Sort(Array & arr)
{
	PrintName();
	int * oddRowArr = 0;
	int size = 0;
	int temp = 0;
	for (int row = 0; row < arr.GetArrRow() && arr.CountOddNumInRow(row) != 0; ++row) {
		size = arr.CountOddNumInRow(row);
		oddRowArr = new int[size];
		arr.OddRow(oddRowArr, row);
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size - i - 1; ++j) {
				if (oddRowArr[j] > oddRowArr[j + 1]) {
					m_num_of_permutations += 1;
					m_num_of_comparisons += 1;
					temp = oddRowArr[j];
					oddRowArr[j] = oddRowArr[j + 1];
					oddRowArr[j + 1] = temp;
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
