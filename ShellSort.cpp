#include "ShellSort.h"

ShellSort::ShellSort()
{
	m_num_of_comparisons = 0;
	m_num_of_permutations = 0;
	m_name = "Сортировка Шелла";
}

void ShellSort::Sort(Array & arr)
{
	PrintName();
	int * oddRowArr = 0;
	int dist = 0,
		size = 0,
		tmp = 0;
	for (int row = 0; row < arr.GetArrRow() && arr.CountOddNumInRow(row) != 0; ++row) {
		size = arr.CountOddNumInRow(row);
		oddRowArr = new int[size];
		arr.OddRow(oddRowArr, row);
		dist = size / 2;
		while (dist > 0) {
			for (int i = 0; i < size - dist; ++i) {
				for (int j = i; j >= 0; --j) {
					if (oddRowArr[j] > oddRowArr[j + dist]) {
						swap(oddRowArr[j], oddRowArr[j + dist]);
						m_num_of_comparisons += 1;
						m_num_of_permutations += 1;
					}
					else {
						m_num_of_comparisons += 1;
					}
				}
			}
			dist /= 2;
		}
		arr.OddRowToArr(oddRowArr, size, row);
		delete oddRowArr;
	}
}
