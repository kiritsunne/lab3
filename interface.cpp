#include "interface.h"
#include<iostream>
#include<locale.h>
//#include"task.h"
#include"enter.h"
#include "test.h"
#include"Array.h"
#include"file.h"

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
	int arrSize = 0/*, mediana = 1*/;
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
			cout << "������� ���������� ��������� �������" << endl;
			input(arrSize);
			while (arrSize <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrSize);
			}
			arr = Array(arrSize);
			cout << "������� �������� ������� (" << arrSize << "):" << endl;
			for (int i = 0; i < arrSize; ++i) {
				cout << "[" << i + 1 << "]: ";
				input(arr[i]);
			}
			break;
		}
					  //���� �� �����
		case INP_FILE: {
			while (arr.GetArrSize() == 0) {
				cout << "������ ��� �������:" << endl;
				InputFromFile(arr);
			}
			break;
		}
					   //���� ������������ �����
		case RANDOM: {
			cout << "������� ���������� ��������� �������" << endl;
			input(arrSize);
			while (arrSize <= 0) {
				cout << "���������� ��������� ������� �� ����� ���� ������������� ��� �������." << endl
					<< "������� ���������� ��������" << endl;
				input(arrSize);
			}
			arr = Array(arrSize);
			for (int i = 0; i < arrSize; ++i) {
				arr[i] = RandomInt(FROM, TO);
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
		if (flagExitSubMenu && arr.GetArrSize() > 0) {
			cout << "������ ������� " << arr.GetArrSize() << endl;
			for (int i = 0; i < arr.GetArrSize(); ++i) {
				cout << "[" << i + 1 << "]: " << arr[i] << ", ";
			}
			
			/*
			�������� �� ����������
			mediana = Mediana(arr);
			cout << endl << "����� �������� ������� �������: " << mediana << endl << endl;
			for (int i = 0; i < arr.GetArrSize(); ++i) {
				if (i == mediana - 1) {
					setColor(Green, White);
					cout << "[" << i + 1 << "]: " << arr[i] << ", ";
					setColor(Black, White);
				}
				else {
					cout << "[" << i + 1 << "]: " << arr[i] << ", ";
				}
			}
			*/
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
			if (flagSaveToFile)
				//SaveResultToFile(arr, Mediana(arr));

			userChoice = RETURN;
		}
		system("pause");

	} while (userChoice != RETURN);
}