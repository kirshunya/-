#include <stdio.h>
#include <stdlib.h>
#include <process.h> 
int main()
{
	int size = 0;
	int sum = 0;
	int array[100][100] = { 0 };
	printf("Enter the matrix size\n");
	while (scanf_s("%d", &size) != 1 || size > 100 || size < 0 || getchar() != '\n')
	{
		printf("Wrong input,try again\n");
		rewind(stdin);
	}
	srand(_getpid());
	int oper;
	printf("Choose an operation:\n1: Random\n2: Keyboard\nSelected operation: ");

	while (scanf_s("%d", &oper) != 1 || oper > 2 || oper < 1 || getchar() != '\n')
	{
		printf("\nError.\tInput number: ");
		rewind(stdin);
	}
	switch (oper)
	{
	case 1:
	{
		for (int i = 0; i <= size; i++)
		{
			for (int j = 0; j <= size; j++)
			{
				array[i][j] = rand() % 10;
			}
		}
	}
	break;
	case 2:
		printf("Enter the array elements:\n");
		{
			for (int i = 0; i <= size; i++)
			{
				for (int j = 0; j <= size; j++)
				{
					while (scanf_s("%d", &array[i][j]) != 1 || getchar() != '\n')
					{
						printf("\nError.\tInput number: ");
						rewind(stdin);
					}
				}
			}
		}
		break;
	}
	printf("\nMatrix:\n");
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++) {
			printf(" %d \t", array[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i <= size; i++)
	{
		if (i <= size / 2)
		{
			for (int j = size; j >= size - i + 1; j--)
			{
				sum += array[i][j];
				printf("\nSum1:%d ", sum);
			}
		}
		else
		{
			for (int j = size; j >= i; j--)
			{
				sum += array[i][j];
				printf("\nSum2: %d ", sum);

			}

		}

	}
	printf("\nSum: = %d ", sum);

	return 0;
}
