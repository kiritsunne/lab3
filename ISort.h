#pragma once
#include "Array.h"
#include"enter.h"
#include<string>
#include<iostream>
#include<fstream>
#define N 64//длина строки таблицы в символах
using namespace std;

 class ISort
{
public:
	int m_num_of_comparisons;
	int m_num_of_permutations;
	string m_name;

	virtual void Sort(Array & arr) = 0;

	int GetNumOfComparisons() {
		return m_num_of_comparisons;
	}
	int GetNumOfPermutations() {
		return m_num_of_permutations;
	}
	string GetName() {
		return m_name;
	}
	void PrintName() {
		cout << m_name << endl;
	}
	void PrintResult() {
		cout.setf(ios::left);
		cout << "|";
		cout.width(20);
		cout << m_name;
		cout << "|";
		cout.width(20);
		cout << m_num_of_comparisons;
		cout << "|";
		cout.width(20);
		cout << m_num_of_permutations;
		cout << "|" << endl;
		for (int i = 0; i < N; ++i) {
			cout << "-";
		}
		cout << endl;
	}
	void PrintTableLegend() {
		cout.setf(ios::left);
		cout << "|";
		cout.width(20);
		cout << "Название сортировки";
		cout << "|";
		cout.width(20);
		cout << "Кол-во сравнений";
		cout << "|";
		cout.width(20);
		cout << "Кол-во перестановок";
		cout << "|" << endl;
		for (int i = 0; i < N; ++i) {
			cout << "-";
		}
		cout << endl;
	}
	void PrintTableLegendToFile(ofstream & file) {
		file.setf(ios::left);
		file << "|";
		file.width(20);
		file << "Название сортировки";
		file << "|";
		file.width(20);
		file << "Кол-во сравнений";
		file << "|";
		file.width(20);
		file << "Кол-во перестановок";
		file << "|" << endl;
		for (int i = 0; i < N; ++i) {
			file << "-";
		}
		file << endl;
	}
	void PrintResultToFile(ofstream & file) {
		file.setf(ios::left);
		file << "|";
		file.width(20);
		file << m_name;
		file << "|";
		file.width(20);
		file << m_num_of_comparisons;
		file << "|";
		file.width(20);
		file << m_num_of_permutations;
		file << "|" << endl;
		for (int i = 0; i < N; ++i) {
			file << "-";
		}
		file << endl;
	}
};

