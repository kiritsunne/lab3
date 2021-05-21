#include "Array.h"

Array::Array()
{
	m_row = 0;
	m_column = 0;
}

Array::Array(int row, int column)
{
	m_row = row;
	m_column = column;
	m_array = new int*[row];
	for (int i = 0; i < m_row; ++i) {
		m_array[i] = new int[m_column];
	}
}

int* Array::operator[](const int index)
{
	return m_array[index];
}

Array & Array::operator=(const Array & arr)
{
	if (this != &arr) {
		for (int i = 0; i < m_row; ++i) {
			delete m_array[i];
		}
		delete m_array;
		m_row = arr.m_row;
		m_column = arr.m_column;
		m_array = new int*[m_row];
		for (int i = 0; i < m_row; ++i) {
			m_array[i] = new int[m_column];
		}
		for (int i = 0; i < m_row; i++) {
			for (int j = 0; j < m_column; ++j) {
				m_array[i][j] = arr.m_array[i][j];
			}
		}
	}
	return *this;
}

int Array::GetArrRow()
{
	return m_row;
}

int Array::GetArrColumn()
{
	return m_column;
}

int ** Array::GetArrayPointer()
{
	return m_array;
}

void Array::SetArraySize(int row, int column)
{
	m_row = row;
	m_column = column;
}

void Array::SetArrayPointer(int ** array)
{
	m_array = array;
}

void Array::PrintArray()
{
	cout.setf(ios::left);
	cout << "Массив размера [" << m_row << "][" << m_column << "]:" << endl;
	for (int i = 0; i < m_row; ++i) {
		cout << "[" << i + 1 << "]: ";
		for (int j = 0; j < m_column; ++j) {
			
			cout << "[" << j + 1 << "]";
			cout.width(5);
			cout << m_array[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

int Array::CountOddNumInRow(int row)
{
	int count = 0;
	for (int i = 0; i < m_column; ++i) {
		if (IsOdd(m_array[row][i]))
			count += 1;
	}
	return count;
}

void Array::OddRow(int * arr, int row)
{
	for (int i = 0, j = 0; i < m_column; ++i) {
		if (IsOdd(m_array[row][i])) {
			arr[j] = m_array[row][i];
			j += 1;
		}
	}
}

void Array::OddRowToArr(int * arr, int size, int row)
{
	int j = 0;
	for (int i = 0; i < m_column; ++i) {
		if (IsOdd(m_array[row][i])) {
			m_array[row][i] = arr[j];
			j += 1;
		}
	}
}

Array::~Array()
{
		m_row = 0;
		m_column = 0;
		for (int i = 0; i < m_row; ++i) {
			delete m_array[i];
		}
		delete m_array;
}



