#include <stdio.h>
int main(void)
{
	float a, S, V;
	a = 0; //переменная длины ребра
	S = 0; //переменная площади бок. поверхности
	V = 0; //переменная объёма куба 
	printf("Enter the length of the edge of the cube (m) :\n");
	scanf_s("%G", &a);
	printf("a=%G\n", a);//длина ребра куба 
	if (a > 0) {
		V = a * a * a; //расчёт объёма
		S = 6 * a * a; //расчёт площади бок. поверхности 
		printf("The side surface of the cube is equal to (S):%G\n", S);
		printf("The volume of the cube is equal to (V):%G\n", V);
		printf("See you next time))");
		return 0;

	}

	if (a <= 0) {
		printf("You do something wrong (a can't be negative) , try again\n");
		return 0;
	}
}
	
	
