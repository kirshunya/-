#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h> 
#include "lib.h"
void input_size(int *size)//ввод размера 
{
	long long a;
	scanf_s("%lld", &a);
	while (getchar() != '\n')
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%lld", &a);
	}
	*size = a;
}
void input_oper(int* size)//выбор
{
	long long a;
	scanf_s("%lld", &a);
	while (getchar() != '\n'|| a < 1 || a > 2)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%lld", &a);
	}
	*size = a;
}
int *memory(int size)//выделение памяти
{
	int*a=(int*)malloc(size * sizeof(int));
	return a;
}
void input_array(int size,int *mas)//ввод массива
{
	srand(_getpid());
	long long oper=0;
	printf("Enter the operation\n");
	printf("1)random array\n");
	printf("2)manual input array\n");
	scanf_s("%32lld", &oper);
	while (getchar() != '\n'||oper<1||oper>2)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%32lld",&oper);
	}
	switch(oper)
	{
	case 1:
	{
		for (int i = 0; i < size; i++)
		{
				mas[i] = rand() % 10;
		}
	}
	break;
	case 2:
		printf("Enter the array elements:\n");
		{
			for (int i = 0; i < size; i++)
			{
					while (scanf_s("%d", &mas[i]) != 1 || getchar() != '\n')
					{
						printf("\nError.\tInput number: ");
						rewind(stdin);
					}
			}
		}
		break;
	}
}

void min_search(int size,int*mas,int*strt,int*end)//посик позиций минимальных элементов
{
	int c=0;
	int pos1 = -1;
	int pos2 = 0;
	int min = mas[0];
	for (int i = 0; i < size; i++)
	{
		if (min > mas[i])
		{
			min = mas[i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (mas[i]==min)
		{
			if (pos1 != -1)
			{
				pos2 = i;
			}
			else
			{
				pos1 = i;
			}
		}
	}
	printf("\n");
	*strt = pos1;
	*end = pos2;
}
void output_array(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mas[i]);
	}
}
int* memory2(int size)
{
	int* a = (int*)malloc(size * sizeof(int));
	return a;
}
void search(int *mas,int strt,int end,int*temp,int*cnt)//количество чисел на сортировку
{
	int k = 0;
	for (int i = strt; i < end; i++)
	{
		if (mas[i] % 2 != 0)
		{
			temp[k] = mas[i];
			k++;
		}
	}
	*cnt = k;
}
void sort_second(int*temp,int size,int strt,int end,int *mas,int cnt)//сортировка вставками+замена
{
	
	int newElement, location;
	for (int i = 0; i < cnt; i++)
	{
		newElement = temp[i];
		location = i - 1;
		while (location >= 0 && temp[location] > newElement)
		{
		
			temp[location + 1] = temp[location];
			location = location - 1;
		}
	temp[location + 1] = newElement;
	}
	int k = 0;
	for (int i = strt+1; i < end; i++)
	{
		if (mas[i]%2!= 0)
		{
			mas[i] = temp[k];
			k++;
		}
	}
}
void reverse_sorting(int* temp, int size, int strt, int end, int* mas, int cnt)//обратная вставками+замена
{
	int newElement, location;
	for (int i = 0; i < cnt; i++)
	{
		newElement = temp[i];
		location = i - 1;
		while (location >= 0 && temp[location] < newElement)
		{

			temp[location + 1] = temp[location];
			location = location - 1;
		}
		temp[location + 1] = newElement;
	}
	int k = 0;
	for (int i = strt + 1; i < end; i++)
	{
		if (mas[i] % 2 != 0)
		{
			mas[i] = temp[k];
			k++;
		}
	}
}
void bubble(int* mas, int size,int strt,int end,int*temp,int cnt)//бублес+замена
{
	for (int i = 0; i <cnt-1; i++)
	{
		for (int j = cnt-1; j > i; j--) // для всех элементов после i-ого
		{
			if (temp[j - 1] > temp[j]) // если текущий элемент меньше предыдущего
			{
				int tmp = temp[j - 1]; // меняем их местами
				temp[j - 1] = temp[j];
				temp[j] = tmp;
			}
		}
	}
	int k = 0;
	for (int i = strt + 1; i < end; i++)
	{
		if (mas[i] % 2 != 0)
		{
			mas[i] = temp[k];
			k++;
		}
	}
}
void bubble_reverse(int* mas, int size, int strt, int end, int* temp, int cnt)//бублес+замена
{
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = cnt - 1; j > i; j--) // для всех элементов после i-ого
		{
			if (temp[j - 1] < temp[j]) // если текущий элемент меньше предыдущего
			{
				int tmp = temp[j - 1]; // меняем их местами
				temp[j - 1] = temp[j];
				temp[j] = tmp;
			}
		}
	}
	int k = 0;
	for (int i = strt + 1; i < end; i++)
	{
		if (mas[i] % 2 != 0)
		{
			mas[i] = temp[k];
			k++;
		}
	}
}