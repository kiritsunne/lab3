#include "interface.h"
#include<iostream>
#include<locale.h>
#include"enter.h"
#include "test.h"
#include"Array.h"
#include"file.h"
#include"ISort.h"
#include"BubbleSort.h"
#include"SelectionSort.h"
#include"InsertionSort.h"
#include"ShellSort.h"
#include"QuickSort.h"

#define FROM -100
#define TO 100

using namespace std;
//������������ ������ ��� ������ ������ ����
enum menu {
	EXIT,
	TASK,
	TEST
};
//������������ ������ ��� ������ ������ �������
enum taskmenu {
	RETURN,//�����
	KEYBORD,//���� � ����������
	INP_FILE,//���� �� �����
	RANDOM//���������� ������� ������������� �������
};
//������� ��� ������ �����������
void Greatings()
{
	cout << "=============" << endl
		<< "�������� �.�." << endl
		<< "������ �404" << endl
		<< "Email: daiti.ru.ua@gmail.com" << endl
		<< "������������ ������ �3" << endl
		<< "������� �11" << endl
		<< "���������� ��������� ��������� ��� ���������� ������� ������ ��������:" << endl
		<< "�����������, ������, �������, ����� � ������� ����������.������� �� �����" << endl
		<< "���������������(���� ���) � �������������(��� ������� �� �������) �������" << endl
		<< "������. ��������� ������������� ������� ������������� �������, � �������" << endl
		<< "���������� ������� ����� ��������� � ������������ ���������� � ������" << endl
		<< "������ ����������" << endl
		<< "����������� ��� �������� �������� (�������� ���������) ����� �� �����������." << endl
		<< "=============" << endl;
	system("pause");
}
//������� ��� ������ � �������������� � ����
void Menu()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;

	do
	{
		system("cls");
		cout << "������������ ������ �1" << endl
			<< "1 - ���������� �������" << endl
			<< "2 - ������������" << endl
			<< "0 - �����" << endl;

		input(userChoice);

		switch (userChoice)
		{
		case TASK: {
			system("cls");
			MenuTask();
			break;
		}
		case TEST: {
			system("cls");
			cout << "������������" << endl << endl;
			Test();
			system("pause");
			break;
		}
		case EXIT: break;
		default: {
			cout << "������� ���������� ��������!" << endl;
			system("pause");
			break;
		}
		}

	} while (userChoice != EXIT);
}
//������� ��� ������ � ������������ � �������� �������
void MenuTask()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;
	int arrRow = 0, arrColumn = 0/*, mediana = 1*/;
	Array arr;

	//���� ������ �� �������
	//false - �� �������� �� �������
	//true - ����� �� �������
	bool flagExitSubMenu = true;

	//���� ���������� � ����
	//false - �� ��������� ������ � ����
	//true - ��������� ������ � ����
	bool flagSaveToFile = false;


	do
	{
		system("cls");
		cout << "1 - ���� � ����������" << endl
			<< "2 - ���� �� �����" << endl
			<< "3 - �������������� ���� ������������ ��������" << endl
			<< "0 - �����" << endl;
		input(userChoice);

		switch (userChoice)
		{
			//���� ������ � ����������
		case KEYBORD: {
			cout << "������� ���������� ����� �������" << endl;
			input(arrRow);
			while (arrRow <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrRow);
			}
			cout << "������� ���������� �������� �������" << endl;
			input(arrColumn);
			while (arrColumn <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrColumn);
			}
			arr = Array(arrRow, arrColumn);
			cout << "������� �������� ������� [" << arrRow << "][" << arrColumn << "]:" << endl;
			for (int i = 0; i < arrRow; ++i) {
				for (int j = 0; j < arrColumn; ++j) {
					cout << "[" << i + 1 << "][" << j + 1 << "]:";
					input(arr[i][j]);
				}
				
			}
			break;
		}
		//���� �� �����
		case INP_FILE: {
			while (arr.GetArrRow() == 0) {
				cout << "������ ��� �������:" << endl;
				InputFromFile(arr);
			}
			break;
		}
					   //���� ������������ �����
		case RANDOM: {
			cout << "������� ���������� ����� �������" << endl;
			input(arrRow);
			while (arrRow <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrRow);
			}
			cout << "������� ���������� �������� �������" << endl;
			input(arrColumn);
			while (arrColumn <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrColumn);
			}
			arr = Array(arrRow, arrColumn);
			for (int i = 0; i < arrRow; ++i) {
				for (int j = 0; j < arrColumn; ++j) {
					arr[i][j] = RandomInt(FROM, TO);
				}
			}
			break;
		}
					 //��������� � ������� ����
		case RETURN: {
			flagExitSubMenu = false;
			break;
		}
		default: {
			cout << "������� ���������� ��������!" << endl;
			system("pause");
			break;
		}
		}
		//����������� ���� ���� ������� ������ �������
		//� �� ������ ����� �����
		if (flagExitSubMenu && arr.GetArrRow() > 0) {
			arr.PrintArray();
			Array tempArray;
			tempArray = arr;

			BubbleSort bSort;
			bSort.Sort(tempArray);
			tempArray.PrintArray();
			tempArray = arr;

			SelectionSort sSort;
			sSort.Sort(tempArray);
			tempArray.PrintArray();
			tempArray = arr;
			
			InsertionSort iSort;
			iSort.Sort(tempArray);
			tempArray.PrintArray();
			tempArray = arr;

			ShellSort shSort;
			shSort.Sort(tempArray);
			tempArray.PrintArray();
			tempArray = arr;

			QuickSort qSort;
			qSort.Sort(tempArray);
			tempArray.PrintArray();
			tempArray = arr;

			shSort.PrintTableLegend();
			bSort.PrintResult();
			sSort.PrintResult();
			iSort.PrintResult();
			shSort.PrintResult();
			qSort.PrintResult();
			
			cout << endl << "������� ��������� �������� ������ � ����?" << endl
				<< "1 - ��" << endl
				<< "0 - ���" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile)
				SaveInitialDataToFile(arr);

			cout << "������� ��������� ��������� � ����?" << endl
				<< "1 - ��" << endl
				<< "0 - ���" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile) {
				SaveResultToFile(arr, bSort, sSort, iSort, shSort, qSort);
			}
			userChoice = RETURN;
		}
		system("pause");

	} while (userChoice != RETURN);
}