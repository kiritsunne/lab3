#include <cmath>


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
