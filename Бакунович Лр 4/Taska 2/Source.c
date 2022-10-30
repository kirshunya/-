#include <stdio.h>
#include <stdlib.h>
#include <process.h> 

int resh, col, row = 0;
int i, j = 0;
int array[100][100] = { 0 };
//int min = array[0][0];
void input_numb(int array[100][100])
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
void rnd(int array[100][100])//random func.
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
			for (int j = 0; j <= col; j++)
			{
				array[i][j] = rand() % 1000 - 650;
			}
		}
	}
	break;
	case 2:
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
	printf("\nMatrix:\n");
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++) {
			printf("%d \t",  array[i][j]);
		}
		printf("\n");
	}
}
void search(int array[100][100])
{
	int h=row;
	int k = 0;
	int frst = 0;
	int cntr = 0;
	for (int i = 0; i <= row; i++)
	{
		if (array[i][0] < 0)
		{
			for (int j = 0; j <= col; j++)
			{
				if (array[i][j] < 0)
				{
					cntr++;
					if ( k == 0)
					{ 
						if (cntr == row + 1)
						{
							printf("\n");
							printf("The row with all negative elements is under the number = %d\n", i);
							k++;
							if (frst == 0)
							{
								frst= array[i][0];
								printf("\n");
								printf("First negative element is %d\n", frst);
							}
							if (frst != 0)
							{
								printf("\nEnlarged array:\n");
								for (int i = 0; i <= row; i++)
								{
									for (int j = 0; j <= col; j++) {
										printf(" %d \t", array[i][j]+frst);
									}
									printf("\n");
								}
							}
						}
					}
				}
			}
			
		}
		cntr = 0;
	}
	
}
int main()
{	
	input_numb(array[100][100]);
	rnd(array[100][100]);
	conclusion(array[100][100]);
	search(array[100][100]);
	return 0;

}