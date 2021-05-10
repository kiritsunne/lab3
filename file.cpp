#include "file.h"
#include<filesystem>
#include<fstream>
#include<iostream>
#include<string>
#include"enter.h"

enum saveMenu {
	INEXISTSAVE = 1,
	INMEWSAVE
};

using namespace std;
namespace fs = std::experimental::filesystem;
//���� ���������� � ����
string SaveToFile() {
	cout << "����������:" << endl
		<< "1 - ��������� � ������������ ����" << endl
		<< "2 - ��������� � ����� ����" << endl;
	int userChoice = -1;
	input(userChoice);
	string filePath;
	while (!(userChoice >= 1 && userChoice <= 2)) {
		cout << "������ ������ ���� �� ����������. ������� ���������� ��������" << endl;
		input(userChoice);
	}
	switch (userChoice)
	{
		//���������� � ������������ ����
	case INEXISTSAVE: {
		filePath = EnterFilePath();
		while (!CheckExistFile(filePath)) {
			cout << "������� ���������� ���� � �����" << endl;
			filePath = EnterFilePath();
		}
		break;
	}
					  //���������� � ����� ����
	case INMEWSAVE: {
		filePath = EnterFilePath();
		while (!CreateNewFile(filePath)) {
			cout << "������� ���������� ���� � �����" << endl;
			filePath = EnterFilePath();
		}
		break;
	}
	}
	return filePath;
}
//���������� ���������� � ����
/*
�������� ��������� ���������� �� ��������� ����������� ���������� � �������
void SaveResultToFile(Array &arr, int result)
{
	ofstream file(SaveToFile(), ios_base::app);
	if (file.is_open()) {
		file << "������ ������� " << arr.GetArrSize() << endl;
		for (int i = 0; i < arr.GetArrSize(); ++i) {
			file << arr[i] << " ";
		}
		file << "������� �������: " << result << endl << endl;
		cout << "���������� ���������" << endl;
	}
	else {
		cout << "�� ������� ������� ����" << endl;
	}

	file.close();
}
*/
//���������� ��������� ������ � ����
//���� ������ ���������� ��������� ������ ����� �������
//��������� �� ���������� �� ��� ������ ��������� ������ �� �����
void SaveInitialDataToFile(Array & arr)
{
	ofstream file(SaveToFile(), ios_base::app);
	if (file.is_open()) {
		file << "[INPUT]" << endl
			<< "������ ������� N= " << arr.GetArrSize() << endl
			<< "[ ";
		for (int i = 0; i < arr.GetArrSize(); ++i) {
			file << arr[i] << " ";
		}
		file << "]" << endl;

		cout << "���������� ���������" << endl;
	}
	else {
		cout << "�� ������� ������� ����" << endl;
	}

	file.close();
}
//���� �� �����
void InputFromFile(Array & arrayToReturn)
{
	string filePath;
	filePath = EnterFilePath();

	while (!CheckExistFile(filePath)) {
		cout << "������� ���������� ���� � �����" << endl;
		filePath = EnterFilePath();
	}

	ifstream file(filePath, ios_base::binary);
	int arraySize = 0;

	bool
		//���� ������������ ��������� ������������
		//������������� ��� ������ ����������
		//�� ���� ��������� � �������� true
		agreeFlag = false,

		//true - ���� � ����� ��� ������ ��� ������
		emptyDataFlag = true,

		//true - ���� ������ ��� ����� ���������
		//���� ���� ������ � ������������� ������ � �����,
		//��������� �� ���������� � �������
		//��������� � �������������� ������ ��������
		correctFileInputFlag = true;

	string bufString;
	int bufNum, counter = 0;
	while (!file.eof() && !agreeFlag) {

		file >> bufString;
		if (bufString == "[INPUT]") {
			emptyDataFlag = false;

			cout << "input" << endl;
			while (bufString != "N=") {
				file >> bufString;
			}
			correctFileInputFlag = (fileInput(file, arraySize) && arraySize > 0);
			if (correctFileInputFlag)
				arrayToReturn = Array(arraySize);

			while (bufString != "[") {
				file >> bufString;
			}
			counter = 0;
			for (int i = 0; i < arraySize; ++i) {
				correctFileInputFlag &= fileInput(file, bufNum);
				if (correctFileInputFlag && (arrayToReturn.GetArrayPointer() != 0)) {
					arrayToReturn[i] = bufNum;
				}
			}

			if (correctFileInputFlag) {
				cout << "������ ������� " << arraySize << endl;
				for (int i = 0; i < arraySize; ++i) {
					cout << arrayToReturn[i] << " ";
				}

				cout << "������� ������ ������?" << endl
					<< "1 - ��" << endl
					<< "0 - ���" << endl;

				input(agreeFlag);
			}
			else {
				agreeFlag = false;
			}
			correctFileInputFlag = true;
		}
	}
	if (emptyDataFlag == true) {
		cout << "��� ������ ��� ������" << endl;
	}
	file.close();
}
//�������� ������������� �����
bool CheckExistFile(string &filePath) {
	bool correctFileFlag = false;
	if (fs::exists(fs::status(filePath))) {
		correctFileFlag = true;
	}
	else {
		cout << "���� �� ����������" << endl;
		correctFileFlag = false;
	}
	if (correctFileFlag && !fs::is_regular_file(fs::status(filePath))) {
		cout << "�� ���������� ����. ������ � ������ ����������" << endl;
		correctFileFlag = false;
	}
	return correctFileFlag;
}
//�������� ����� ��� ����������
bool CreateNewFile(string &filePath) {

	if (fs::exists(fs::status(filePath))) {
		cout << "����� ���� ��� ����������" << endl;
		return false;
	}

	bool correctFileFlag = false;
	ofstream file(filePath);

	if (file.is_open()) {
		if (!fs::is_regular_file(fs::status(filePath))) {
			cout << "�� ���������� ����. ������ � ������ ����������" << endl;
			correctFileFlag = false;
		}
		else {
			cout << "���� ������ � ����� � ������" << endl;
			correctFileFlag = true;
		}
	}

	else {
		cout << "���� �� ������" << endl;
		cout << "����������� ������ ���� � �����" << endl
			<< "��������� �������� ���� � ���������� �����" << endl;
		correctFileFlag = false;
	}

	file.close();
	return correctFileFlag;
}
//���� ���� � ����� � ��� ��������
string EnterFilePath()
{
	string filePath = "";
	unsigned int sizeOfPath = UINT32_MAX;
	cout << "������� ���� � �����. ���������� ����� .txt" << endl;
	input(filePath);
	sizeOfPath = filePath.length();
	while (!(filePath.find(".txt") < sizeOfPath)) {
		cout << "����������� ������ ���� � �����" << endl
			<< "��������� �������� ���� � ���������� �����" << endl;
		input(filePath);
		sizeOfPath = filePath.length();
	}
	return filePath;
}