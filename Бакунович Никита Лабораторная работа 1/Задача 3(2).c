#include <stdio.h>

int main()
{
	float a, b, c;
	int S;
	S = 0;
	printf("Enter the number a \n");
	scanf_s("%G",&a);
	printf("a=%G\n",a);
	printf("Enter the number b \n");
	scanf_s("%G", &b);
	printf("b=%G\n", b);
	printf("Enter the number c \n");
	scanf_s("%G", &c);
	printf("c=%G\n", c);
	if (a > 0) { // проверка числа а 
		S = S + 1;
	}
	else {
		S = S+0;
	}
	if (b > 0) { // проверка числа б 
		S = S + 1;
	}
	else {
		S = S+0;
	}
	if (c > 0) { // проверка числа с 
		S = S + 1;
	}
	else {
		S =S+0;
	}
	printf("The number of positive numbers is equal to :%i", S);
	return 0;
}

