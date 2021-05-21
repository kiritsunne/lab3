#include<iostream>
#include<locale.h>
#include"interface.h"
#include <time.h>

using namespace std;

int main(void) {
	srand(static_cast<unsigned int>(time(NULL)));
	setlocale(LC_ALL, "RU");

	Greatings();
	Menu();

	return 0;
}