#include <stdio.h>
int main(void)
{
	float x, y, C, R;
	x, y, C = 0;
	R = 1; //радиус единичной окружности 
	printf("Enter the value of X:\n"); //ввод координаты х
	scanf_s("%G", &x);
	printf("X=%G\n", x);
	printf("Enter the value of Y:\n"); //ввод координаты у
	scanf_s("%G", &y);
	printf("Y=%G\n", y);
	printf("Check whether the point belongs to the unit circle.....\n");
	C = x * x + y * y; //формула окружности 
	printf("%G\n", C);
	if (R*R == C*C) { //условие принадлежности точки к окружности 
		printf("The Point belong to the circle\n");
		return 0;
	}
	if (R*R != C*C) { 

		printf("The point does not belong the circle\n");
		return 0;
	}
	return 0;
}