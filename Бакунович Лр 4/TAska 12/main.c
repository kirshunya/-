#include <stdio.h>
#include <stdlib.h>
#include <process.h> 

int col, row = 0;
int array[100][100];
//int min = array[0][0];
void input_numb()
{


	printf("Enter the dimension of rows\n");
	while (scanf_s("%d", &row) != 1 || row > 100 || row < 0 || getchar() != '\n')
	{
		printf("Wrong input,try again\n");
		rewind(stdin);
	}
	printf("Enter the dimension of columns\n");
	while (scanf_s("%d", &col) != 1 || col > 100 || col < 0 || getchar() != '\n')
	{
		printf("Wrong input,try again\n");
		rewind(stdin);
	}

}
void rnd()//random func.
{
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
		for (int i = 0; i <= row; i++)
		{
			for (int j = 0; j <=col; j++)
			{
				array[i][j] = rand() % 10;
			}
		}
	}
	break;
	case 2:
		printf("Enter the array elements:\n");
		{
			for (int i = 0; i <= row; i++)
			{
				for (int j = 0; j <= col; j++)
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
}

void conclusion()//exit array
{
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			printf(" %d \t", array[i][j]);
		}
		printf("\n");
	}
}
void min_max()
{
	int k = 0;
	int max1, min1, f1 = 0;
	int max2, min2, f2 = 0;
	printf("\n");
	for (int i = 0; i <= row; i++)
	{
		min1 = array[i][0];
		for (int x = 1; x <= col; x++)
		{
			if (array[i][x] < min1)
			{
				min1 = array[i][x];
			}
		}
		for (int j = 0; j <= col; j++)
		{
			if (array[i][j] == min1)
			{
				max1 = array[0][j];
				for (int y = 1; y <= row; y++)
				{
					if (array[y][j] > max1)
					{
						max1 = array[y][j];
					}
				}
				if (array[i][j] == max1)
				{
					printf("Saddle point:[%d][%d]=%d\n", i, j, array[i][j]);
					f1 = 1;
				}
			}
		}
	}
	if (!f1)
	{
		printf("The matrix has no saddle points!(1;max)\n");
	}
	////////////////////////////////////
	for (int i = 0; i <= row; i++)
	{
		max1 = array[i][0];
		for (int x = 1; x <= col; x++)
		{
			if (array[i][x] > max1)
			{
				max1 = array[i][x];
			}
		}
		for (int j = 0; j <= col; j++)
		{
			if (array[i][j] == max1)
			{
				min1 = array[0][j];
				for (int y = 1; y <= row; y++)
				{
					if (array[y][j] < min1)
					{
						min1 = array[y][j];
					}
				}
				if (array[i][j] == min1)
				{
					printf("Saddle point:[%d][%d]=%d\n", i, j, array[i][j]);
					f2 = 1;
				}
			}
		}
	}
	if (!f2)
	{
		printf("The matrix has no saddle points!(2;min)\n");
	}
}
int main()
{

	input_numb();
	rnd();
	conclusion();
	min_max();
	return 0;

}