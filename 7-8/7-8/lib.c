#include <stdio.h>
#include<stdlib.h>
#include "lib.h"
int input_oper(int*size)
{
	long long a;
	scanf_s("%lld", &a);
	while (getchar() != '\n'||a>4||a<1)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%lld", &a);
	}
	*size = a;
	return*size;
}
void clear_and_stop_console()
{
	rewind(stdin);
	getchar();
	system("cls");
}
void menu()
{
	printf("Chose the task:\n");
	printf("1)Task 1(7)\n");
	printf("2)Task 2(7)\n");
	printf("3)Task 1(8)\n");
	printf("4)Stop\n");
}
char* string_memory(char*str)
{
	str = malloc(256);
	return str;
}
char* string_input(char*str)
{
	gets_s(str, 256);
	return str;
}
char* string_output(char*str)
{
	puts(str);
	return str;
}
char* string_memory_realloc(char*str)
{
	int leng = 0;
	leng = sizeof(str);
	printf("%d\n", leng);
	str = realloc(str, leng * sizeof(char));
	return str;
}
char* get_string(int* len) {
	*len = 0; // изначально строка пуста
	int capacity = 1; // ёмкость контейнера динамической строки (1, так как точно будет '\0')
	char* s = (char*)malloc(sizeof(char)); // динамическая пустая строка
	char c = getchar(); // символ для чтения данных
	// читаем символы, пока не получим символ переноса строки (\n)
	while (c != '\n') {
		s[(*len)++] = c; // заносим в строку новый символ
		// если реальный размер больше размера контейнера, то увеличим его размер
		if (*len >= capacity) {
			capacity *= 2; // увеличиваем ёмкость строки в два раза
			s = (char*)realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной ёмкостью  
		}
		c = getchar(); // считываем следующий символ          
	}
	s[*len] = '\0'; // завершаем строку символом конца строки
	return s; // возвращаем указатель на считанную строку
}
char* down_first(char* str,int len)
{
	for (int i = 0; i < len; i++)
		if (str[i] == ' '|| str[i] == '\t'|| str[i] == '  '|| str[i] == '   ')
		{
			i++;
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 'a' + 'A';
			}
		}
		else if (i == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
		}
	return str;
}
int input_num(int* size)
{
	long long a;
	scanf_s("%lld", &a);
	while (getchar() != '\n' || a <0)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf_s("%lld", &a);
	}
	*size = a;
	return*size;
}
char* input_new_string(char*s1,char*s2,char*s3,int n1,int n2,int len2)
{
	int pos = 0;
	int len = 0;
	s3 = (char*)calloc(1,sizeof(char));
	for (int i = 0; i < n1; i++)
	{
		if (s1[i] == ' ')
			i++;
		s3[pos] = s1[i];
		pos++;
	}
	for (int i =0; i <= len2; i++)
	{
		if (s2[i] == ' ')
			i++;
		s3[pos] = s2[i];
		pos++;
	}
	//s3 = (char*)realloc(s3,(pos)*sizeof(char));
	return s3;
}