#pragma once

#include<iostream>
#include<fstream>

using namespace std;

template <typename NUM> void input(NUM& arg);
template <typename NUM> bool fileInput(ifstream &file, NUM &arg);
int RandomInt(int leftSide, int rightSide);

template <typename NUM> inline void input(NUM &arg)
{
	NUM _buffer; bool error;

	while (true) {
		cin >> _buffer;
		error = (cin.fail() || cin.bad());
		if (error) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������ �����! ���������, ����������" << endl;
		}
		else break;
	}
	cin.ignore(cin.rdbuf()->in_avail());
	arg = _buffer;
}

template <typename NUM> inline bool fileInput(ifstream &file, NUM &arg)
{
	NUM _buffer; bool error;

	file >> _buffer;

	error = (file.bad() || file.fail());
	if (error) {
		cout << "������ ������ �������!" << endl;
		file.clear();
		file.ignore();
		return false;
	}
	else {
		arg = _buffer;
		return true;
	}
}