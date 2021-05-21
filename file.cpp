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
//Меню сохранения в файл
string SaveToFile() {
	cout << "Сохранение:" << endl
		<< "1 - Сохранить в существующий файл" << endl
		<< "2 - Сохранить в новый файл" << endl;
	int userChoice = -1;
	input(userChoice);
	string filePath;
	while (!(userChoice >= 1 && userChoice <= 2)) {
		cout << "Такого пункта меню не существует. Введите корректное значение" << endl;
		input(userChoice);
	}
	switch (userChoice)
	{
		//сохранение в существующий файл
	case INEXISTSAVE: {
		filePath = EnterFilePath();
		while (!CheckExistFile(filePath)) {
			cout << "Введите корректный путь к файлу" << endl;
			filePath = EnterFilePath();
		}
		break;
	}
					  //сохранение в новый файл
	case INMEWSAVE: {
		filePath = EnterFilePath();
		while (!CreateNewFile(filePath)) {
			cout << "Введите корректный путь к файлу" << endl;
			filePath = EnterFilePath();
		}
		break;
	}
	}
	return filePath;
}
//Сохранение результата в файл

//ИЗМЕНИТЬ ОХРАНЕНИЕ РЕЗУЛЬТАТА НА ОСНОВАНИИ РЕЗУЛЬТАТОВ СОРТИРОВКИ И ТАБЛИЦЫ
void SaveResultToFile(Array & arr, BubbleSort & bSort, SelectionSort & sSort, InsertionSort & iSort, ShellSort & shSort, QuickSort & qSort)
{
	ofstream file(SaveToFile(), ios_base::app);
	if (file.is_open()) {
		file.setf(ios::left);
		file << "Массив размера [" << arr.GetArrRow() << "][" << arr.GetArrColumn() << "]:" << endl;
		for (int i = 0; i < arr.GetArrRow(); ++i) {
			file << "[" << i + 1 << "]: ";
			for (int j = 0; j < arr.GetArrColumn(); ++j) {

				file << "[" << j + 1 << "]";
				file.width(5);
				file << arr[i][j];
				file << " ";
			}
			file << endl;
		}

		file << endl << "Результаты сортировок" << endl;
		SaveResultSortToFile(arr, bSort, file);
		SaveResultSortToFile(arr, sSort, file);
		SaveResultSortToFile(arr, iSort, file);
		SaveResultSortToFile(arr, shSort, file);
		SaveResultSortToFile(arr, qSort, file);
		file << endl << "Таблица результатов сортировки" << endl;
		bSort.PrintTableLegendToFile(file);
		bSort.PrintResultToFile(file);
		sSort.PrintResultToFile(file);
		iSort.PrintResultToFile(file);
		shSort.PrintResultToFile(file);
		qSort.PrintResultToFile(file);
		cout << "Сохранение завершено" << endl;
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}

	file.close();
}

//Сохранение начальных данных в файл
//если формат сохранения начальных данных будет нарушен
//программа не распознает их при чтении начальных данных из файла
void SaveInitialDataToFile(Array & arr)
{
	ofstream file(SaveToFile(), ios_base::app);
	if (file.is_open()) {
		file << "[INPUT]" << endl
			<< "Массив размера N[ " << arr.GetArrRow() << " ][ " << arr.GetArrColumn() << " ]" << endl;
		for (int i = 0; i < arr.GetArrRow(); ++i) {
			file << "[ ";
			for (int j = 0; j < arr.GetArrColumn(); ++j) {
				file << arr[i][j] << " ";
			}
			file << " ]" << endl;
		}
		cout << "Сохранение завершено" << endl;
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}

	file.close();
}
//ввод из файла
void InputFromFile(Array & arrayToReturn)
{
	string filePath = "";
	filePath = EnterFilePath();

	while (!CheckExistFile(filePath)) {
		cout << "Введите корректный путь к файлу" << endl;
		filePath = EnterFilePath();
	}

	ifstream file(filePath, ios_base::binary);
	//int arraySize = 0;
	int arrayRow = 0, arrayColumn = 0;

	bool
		//если пользователь соглавсен использовать
		//представлнные ему данные окружности
		//то флаг переходит в значение true
		agreeFlag = false,

		//true - если в файле нет данных для выбора
		emptyDataFlag = true,

		//true - если данные для ввода корректны
		//если есть ошибка в представлении данных в файле,
		//программа их пропускает и выводит
		//сообщение о неккоректности данных значений
		correctFileInputFlag = true;

	string bufString;
	int bufNum, counter = 0;
	while (!file.eof() && !agreeFlag) {

		file >> bufString;
		if (bufString == "[INPUT]") {
			emptyDataFlag = false;

			cout << "input" << endl;
			while (bufString != "N[") {
				file >> bufString;
			}
			correctFileInputFlag = (fileInput(file, arrayRow) && arrayRow > 0);
			while (bufString != "][") {
				file >> bufString;
			}
			correctFileInputFlag = (fileInput(file, arrayColumn) && arrayColumn > 0);

			if (correctFileInputFlag)
				arrayToReturn = Array(arrayRow, arrayColumn);

			for (int i = 0; i < arrayRow; ++i) {
				while (bufString != "[") {
					file >> bufString;
				}
				for (int j = 0; j < arrayColumn; ++j) {
					correctFileInputFlag &= fileInput(file, bufNum);
					if (correctFileInputFlag && (arrayToReturn.GetArrayPointer() != 0)) {
						arrayToReturn[i][j] = bufNum;
					}
				}
				file >> bufString;
			}

			if (correctFileInputFlag) {
				cout << "Массив размера [" << arrayRow << "][" << arrayColumn << "]:" << endl;
				for (int i = 0; i < arrayRow; ++i) {
					for (int j = 0; j < arrayColumn; ++j) {
						cout << arrayToReturn[i][j] << " ";
					}
					cout << endl;
				}

				cout << "Выбрать данный массив?" << endl
					<< "1 - Да" << endl
					<< "0 - Нет" << endl;

				input(agreeFlag);
				if (!agreeFlag) {
					arrayToReturn.SetArraySize(0, 0);
				}
			}
			else {
				agreeFlag = false;
				arrayToReturn.SetArraySize(0, 0);
			}
			correctFileInputFlag = true;
		}
	}
	if (emptyDataFlag == true) {
		cout << "Нет данных для выбора" << endl;
	}
	file.close();
}
//Проверка существующего файла
bool CheckExistFile(string & filePath) {
	bool correctFileFlag = false;
	if (fs::exists(fs::status(filePath))) {
		correctFileFlag = true;
	}
	else {
		cout << "Файл не существует" << endl;
		correctFileFlag = false;
	}
	if (correctFileFlag && !fs::is_regular_file(fs::status(filePath))) {
		cout << "Не регулярный файл. Запись и чтение невозможны" << endl;
		correctFileFlag = false;
	}
	return correctFileFlag;
}
//создание файла для сохранение
bool CreateNewFile(string & filePath) {

	if (fs::exists(fs::status(filePath))) {
		cout << "Такой файл уже существует" << endl;
		return false;
	}

	bool correctFileFlag = false;
	ofstream file(filePath);

	if (file.is_open()) {
		if (!fs::is_regular_file(fs::status(filePath))) {
			cout << "Не регулярный файл. Запись и чтение невозможны" << endl;
			correctFileFlag = false;
		}
		else {
			cout << "Файл создан и готов к записи" << endl;
			correctFileFlag = true;
		}
	}

	else {
		cout << "Файл не создан" << endl;
		cout << "Неккоректно введен путь к файлу" << endl
			<< "Проверьте вводимый путь и расширение файла" << endl;
		correctFileFlag = false;
	}

	file.close();
	return correctFileFlag;
}
//ввод пути к файлу и его проверка
string EnterFilePath()
{
	string filePath = "";
	unsigned int sizeOfPath = UINT32_MAX;
	cout << "Введите путь к файлу. Расширение файла .txt" << endl;
	input(filePath);
	sizeOfPath = filePath.length();
	while (!(filePath.find(".txt") < sizeOfPath)) {
		cout << "Некорректно введен путь к файлу" << endl
			<< "Проверьте вводимый путь и расширение файла" << endl;
		input(filePath);
		sizeOfPath = filePath.length();
	}
	return filePath;
}