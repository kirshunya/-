#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include "lib.h"
void input_size_row(int* row)
{
	long long a;
	printf("Enter the rows\n");
	scanf_s("%lld", &a);
	while (getchar() != '\n')
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%lld", &a);
	}
	*row = a;
}
void input_size_coll(int* col)
{
	long long a;
	printf("Enter the colls\n");
	scanf_s("%lld", &a);
	while (getchar() != '\n')
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%lld", &a);
	}
	*col = a;
}
void input_oper(int* size)//выбор
{
	long long a;
	scanf_s("%lld", &a);
	while (getchar() != '\n' || a < 1 || a > 2)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%lld", &a);
	}
	*size = a;
}
int** memory(int row,int col)
{
	int** mas = (int**)malloc(row* sizeof(int*));
	for (int i = 0; i < row+1; i++)
	{
		mas[i] = (int*)malloc((col+5)* sizeof(int));
	}
	return mas;
}
void input(int row,int col,int**mas)
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
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				mas[i][j] = rand() % 10;
			}
		}
	}
	break;
	case 2:
		printf("Enter the array elements:\n");
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					while (scanf_s("%d", &mas[i][j]) != 1 || getchar() != '\n')
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
void output_with_sum(int row,int col,int **mas)
{
	for (int i = 0; i < row+1; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %d \t", mas[i][j]);
		}
		printf("\n");
	}
}
void sum(int row,int col,int**mas)
{
	int sum = 0;
	for (int j = 0; j < col; j++)
	{
		sum = 0;
		for (int i = 0; i < row; i++)
		{
			sum = mas[i][j]+sum;
		}
		mas[row][j] = sum;
	}
}

void bubble_sort(int**mas, int size,int row,int col)
{
	// Для всех элементов
	int end2 = col;
	for (int i = 0; i <end2-1; i++)
	{
		for (int j = (end2-1 ); j > i; j--) // для всех элементов после i-ого
		{
			for (int u = 0; u <= row; u++)
			{
				if (mas[u][j - 1]<mas[u][j]) // если текущий элемент меньше предыдущего
				{
					int temp = mas[u][j - 1]; // меняем их местами
					mas[u][j - 1] = mas[u][j];
					mas[u][j] = temp;
				}
			}
		}
	}
}

void quick_sort(int** mas, int left, int right,int row)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = mas[row][left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((mas[row][right] <= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
				mas[row][left] = mas[row][right];
				for (int u = 0; u < row; u++)
				{
					int tmp = mas[u][left];
					mas[u][left] = mas[u][right];
					mas[u][right] = tmp;
				}

			// перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((mas[row][left] >= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
				mas[row][left] = mas[row][right];
				for (int u = 0; u < row; u++)
				{
					int tmp = mas[u][left];
					mas[u][left] = mas[u][right];
					mas[u][right] = tmp;
				}
			 // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	mas[row][left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quick_sort(mas, left, pivot - 1,row);
	if (right > pivot)
		quick_sort(mas, pivot + 1, right,row);
}
void freshka(int** mas, int row)
{
	for (int i = 0; i < row + 1; i++)
	{
		free(mas[i]); 
	}
	free(mas);
}
void output_without_sum(int row, int col, int** mas)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %d \t", mas[i][j]);
		}
		printf("\n");
	}
}
