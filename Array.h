#pragma once
#include<iostream>
#include"enter.h"
using namespace std;
const class Array
{
private:
	int m_column;
	int m_row;
	int ** m_array;

public:
	Array();
	Array(int row, int column);


	int* operator[](const int index);
	Array & operator=(const Array & arr);
	int GetArrRow();
	int GetArrColumn();
	int ** GetArrayPointer();
	void SetArraySize(int row, int column);
	void SetArrayPointer(int ** array);

	void PrintArray();
	int CountOddNumInRow(int row);
	void OddRow(int * arr, int row);
	void OddRowToArr(int * arr, int size, int row);

	~Array();
};

