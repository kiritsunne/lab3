#pragma once

#include<string>
#include"Array.h"
#include"ISort.h"
#include"BubbleSort.h"
#include"SelectionSort.h"
#include"InsertionSort.h"
#include"ShellSort.h"
#include"QuickSort.h"

using namespace std;
string SaveToFile();
void SaveResultToFile(Array & arr, BubbleSort & bSort, SelectionSort & sSort, InsertionSort & iSort, ShellSort & shSort, QuickSort & qSort);
template <typename SORT> void SaveResultSortToFile(Array & arr, SORT & sort, ofstream & file);
void SaveInitialDataToFile(Array & arr);
void InputFromFile(Array & arrayToReturn);
bool CheckExistFile(string & filePath);
bool CreateNewFile(string & filePath);
string EnterFilePath();

template<typename SORT>
inline void SaveResultSortToFile(Array & arr, SORT & sort, ofstream & file)
{
	if (file.is_open()) {
		file << endl << sort.GetName() << endl;
		Array tempArray;
		tempArray = arr;
		sort.Sort(tempArray);
		file.setf(ios::left);
		file << "Массив размера [" << tempArray.GetArrRow() << "][" << tempArray.GetArrColumn() << "]:" << endl;
		for (int i = 0; i < tempArray.GetArrRow(); ++i) {
			file << "[" << i + 1 << "]: ";
			for (int j = 0; j < tempArray.GetArrColumn(); ++j) {

				file << "[" << j + 1 << "]";
				file.width(5);
				file << tempArray[i][j];
				file << " ";
			}
			file << endl;
		}
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}
}
