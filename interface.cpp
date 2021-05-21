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
//именнованный массив для выбора пункта меню
enum menu {
	EXIT,
	TASK,
	TEST
};
//именнованный массив для выбора пункта подменю
enum taskmenu {
	RETURN,//назад
	KEYBORD,//ввод с клавиатуры
	INP_FILE,//ввод из файла
	RANDOM//заполнение массива произвольными числами
};
//функция для вывода приветствия
void Greatings()
{
	cout << "=============" << endl
		<< "Вересова В.А." << endl
		<< "группа №404" << endl
		<< "Email: daiti.ru.ua@gmail.com" << endl
		<< "Лабораторная работа №3" << endl
		<< "Вариант №11" << endl
		<< "Необходимо составить программу для сортировки массива данных методами:" << endl
		<< "пузырьковой, отбора, вставки, Шелла и быстрой сортировки.Вывести на экран" << endl
		<< "неупорядоченный(один раз) и упорядоченные(для каждого из методов) массивы" << endl
		<< "данных. Составить сравнительную таблицу эффективности методов, в которой" << endl
		<< "необходимо указать число сравнений и перестановок переменных в каждом" << endl
		<< "методе сортировки" << endl
		<< "Упорядочить все нечетные элементы (значения элементов) строк по возрастанию." << endl
		<< "=============" << endl;
	system("pause");
}
//функция для вывода и взаимодействия с меню
void Menu()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;

	do
	{
		system("cls");
		cout << "Лабораторная работа №1" << endl
			<< "1 - Сортировка массива" << endl
			<< "2 - Тестирование" << endl
			<< "0 - Выход" << endl;

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
			cout << "Тестирование" << endl << endl;
			Test();
			system("pause");
			break;
		}
		case EXIT: break;
		default: {
			cout << "Введите корректное значение!" << endl;
			system("pause");
			break;
		}
		}

	} while (userChoice != EXIT);
}
//функция для вывода и взимоействия с пунктами подменю
void MenuTask()
{
	setlocale(LC_ALL, "RU");

	int userChoice = 0;
	int arrRow = 0, arrColumn = 0/*, mediana = 1*/;
	Array arr;

	//флаг выхода из подменю
	//false - не выходить из подменю
	//true - выход из подменю
	bool flagExitSubMenu = true;

	//флаг сохранения в файл
	//false - не сохранять данные в файл
	//true - сохранять данные в файл
	bool flagSaveToFile = false;


	do
	{
		system("cls");
		cout << "1 - Ввод с клавиатуры" << endl
			<< "2 - Ввод из файла" << endl
			<< "3 - Автоматический ввод произвольных значений" << endl
			<< "0 - Назад" << endl;
		input(userChoice);

		switch (userChoice)
		{
			//ввод данных с клавиатуры
		case KEYBORD: {
			cout << "Введите количество строк массива" << endl;
			input(arrRow);
			while (arrRow <= 0) {
				cout << "Количество элементов массива не может быть отрицательным или нулевым." << endl
					<< "Введите корректное значение" << endl;
				input(arrRow);
			}
			cout << "Введите количество столбцов массива" << endl;
			input(arrColumn);
			while (arrColumn <= 0) {
				cout << "Количество элементов массива не может быть отрицательным или нулевым." << endl
					<< "Введите корректное значение" << endl;
				input(arrColumn);
			}
			arr = Array(arrRow, arrColumn);
			cout << "Введите элементы массива [" << arrRow << "][" << arrColumn << "]:" << endl;
			for (int i = 0; i < arrRow; ++i) {
				for (int j = 0; j < arrColumn; ++j) {
					cout << "[" << i + 1 << "][" << j + 1 << "]:";
					input(arr[i][j]);
				}
				
			}
			break;
		}
		//ввод из файла
		case INP_FILE: {
			while (arr.GetArrRow() == 0) {
				cout << "Данные для массива:" << endl;
				InputFromFile(arr);
			}
			break;
		}
					   //ввод произвольных чисел
		case RANDOM: {
			cout << "Введите количество строк массива" << endl;
			input(arrRow);
			while (arrRow <= 0) {
				cout << "Количество элементов массива не может быть отрицательным или нулевым." << endl
					<< "Введите корректное значение" << endl;
				input(arrRow);
			}
			cout << "Введите количество столбцов массива" << endl;
			input(arrColumn);
			while (arrColumn <= 0) {
				cout << "Количество элементов массива не может быть отрицательным или нулевым." << endl
					<< "Введите корректное значение" << endl;
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
					 //вернуться в главное меню
		case RETURN: {
			flagExitSubMenu = false;
			break;
		}
		default: {
			cout << "Введите корректное значение!" << endl;
			system("pause");
			break;
		}
		}
		//выполняется если были введены данные массива
		//и не выбран пункт НАЗАД
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
			
			cout << endl << "Желаете сохранить исходные данные в файл?" << endl
				<< "1 - Да" << endl
				<< "0 - Нет" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile)
				SaveInitialDataToFile(arr);

			cout << "Желаете сохранить результат в файл?" << endl
				<< "1 - Да" << endl
				<< "0 - Нет" << endl;
			input(flagSaveToFile);
			if (flagSaveToFile) {
				SaveResultToFile(arr, bSort, sSort, iSort, shSort, qSort);
			}
			userChoice = RETURN;
		}
		system("pause");

	} while (userChoice != RETURN);
}