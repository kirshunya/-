#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void input(int* n)
{
	while (scanf("%d", &*n) < 0 || getchar() != '\n')
	{
		rewind(stdin);
		printf("\nErorr: please enter correct data:\n");
	}
}
void memory(int* n, int* mas)
{
	mas = (int*)malloc(*n * sizeof(int));
}
void print_array(int* n, int* mas)
{
	for (int i = 0; i < *n; i++)
		printf("%d\t", mas[i]);
}
void input_array(int n, int* mas)
{
	printf("Enter elements:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mas[i]);
		while (getchar() != '\n')
		{
			rewind(stdin);
			printf("\nErorr: please enter correct data:\n");
		}
	}
}
void output_array(int n, int* mas,int flag)
{
	if (flag == 1) {
		printf("\nNew arr:\n");
		for (int i = 0; i < n; i++) {
			printf("%d\t",mas[i]);
		}
	}
	else {
		printf("\nThere are no duplicate elements here\n");

	}
}