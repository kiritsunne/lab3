#include <cmath>
#include "enter.h"


int RandomInt(int leftSide, int rightSide)
{

	if (leftSide > rightSide) {
		leftSide = leftSide + rightSide;
		rightSide = leftSide - rightSide;
		leftSide = leftSide - rightSide;
	}
	if (leftSide < 0) {
		return leftSide + rand() % (abs(leftSide) + rightSide + 1);
	}
	else return leftSide + rand() % (rightSide - leftSide);
}

bool IsOdd(int num)
{
	return (num % 2 == 1)||(num % 2 == -1) ? true : false;
}
