#include<iostream>
#include<locale.h>
#include"interface.h"
#include <time.h>

using namespace std;

int main(void) {
	srand(time(NULL));
	setlocale(LC_ALL, "RU");

	Greatings();
	Menu();

	return 0;
}