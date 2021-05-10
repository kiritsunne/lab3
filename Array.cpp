#include "Array.h"

Array::Array()
{
	m_size = 0;
}

Array::Array(int size)
{
	m_size = size;
	m_array = new int[size];
}

int & Array::operator[](const int index)
{
	return m_array[index];
}

Array & Array::operator=(const Array & arr)
{
	if (this != &arr) {
		delete m_array;
		m_size = arr.m_size;
		m_array = new int[m_size];
		for (int i = 0; i < m_size; i++) {
			m_array[i] = arr.m_array[i];
		}
	}
	return *this;
}

int Array::GetArrSize()
{
	return m_size;
}

int * Array::GetArrayPointer()
{
	return m_array;
}

void Array::SetArraySize(int size)
{
	m_size = size;
}

void Array::SetArrayPointer(int * array)
{
	m_array = array;
}

Array::~Array()
{
	if (m_size != 0) {
		m_size = 0;
		delete m_array;
	}
}



