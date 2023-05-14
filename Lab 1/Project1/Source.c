#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "Source.h"
#define scanf scanf_s

int input()
{
	int b = 0;
	scanf("%d", &b);
	while (getchar() != '\n')
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf("%d", &b);
	}
	return b;
}

int input_oper()
{
	int b;
	scanf("%d", &b);
	while (getchar() != '\n' || b > 6 || b < 1)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf("%d", &b);
	}
	return b;
}

int input_size()
{
	int b;
	scanf("%d", &b);
	while (getchar() != '\n' || b > 100 || b < 1)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf("%d", &b);
	}
	return b;
}

int input_year()
{
	int b = 0;
	scanf("%d", &b);
	while (getchar() != '\n'|| b<0 || b>2024)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf("%d", &b);
	}
	return b;
}

int input_speed()
{
	int b = 0;
	scanf("%d", &b);
	while (getchar() != '\n' || b<0)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf("%d", &b);
	}
	return b;
}

int input_color()
{
	int b = 0;
	scanf("%d", &b);
	while (getchar() != '\n' || b<0 || b>3)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf("%d", &b);
	}
	return b;
}

int input_sorting()
{
	int b = 0;
	scanf("%d", &b);
	while (getchar() != '\n' || b < 0 || b>5)
	{
		rewind(stdin);
		printf("Error,try again\n");
		scanf("%d", &b);
	}
	return b;
}

void clear_and_stop_console()
{
	rewind(stdin);
	getchar();
	system("cls");
}

void color(int num)
{
	switch (num) {
		case RED: {
			printf("Red");
			break;
		}
		case BLACK: {
			printf("Black");
			break;
		}
		case WHITE: {
			printf("White");
			break;
		}
		default: {
			break;
		}
	}
}

void creating(car *cars, int size)
{
		printf("Enter mark of %d car:\n", size + 1);
		fgets(cars[size].mark, 100, stdin);
		cars[size].mark[strlen(cars[size].mark)] = '\0';

		printf("Enter contry of %d car:\n", size + 1);
		fgets(cars[size].country, 100, stdin);
		cars[size].country[strlen(cars[size].country)] = '\0';

		printf("Enter year of %d car:\n ", size + 1);
		cars[size].year = input_year();

		printf("Enter max speed %d of car:\n ", size + 1);
		cars[size].max_speed = input_speed();

		printf("Enter color %d of car:", size + 1);
		printf("\n1)Red\n2)Black\n3)White\n");
		cars[size].color = input_color();
}

car* creating_struct(int* size) {
	printf("Enter the number of objects:\n");
	int ans = input_size();
	*size = ans;
	car* cars = (car*)malloc(ans * sizeof(car));
	for (int i = 0; i < ans; i++)
	{
		cars[i].mark = (char*)calloc(1,2* sizeof(char));
		cars[i].country = (char*)calloc(1,2* sizeof(char));
	}
	for (int i = 0; i < ans; i++) {
		creating(cars, i);
		printf("\n");
	}
	return cars;
}

void showing(car*cars, int size)
{
	for (int i = 0; i < size; i++) {
		
		printf_s("%d)", i + 1);
		printf_s("%s", "Mark: ");
		for (int j = 0; j < strlen(cars[i].mark); j++) {
			printf_s("%c", cars[i].mark[j]);
		}
		printf_s("%d)", i + 1);
		printf_s("%s", "Country: ");
		for (int j = 0; j < strlen(cars[i].country); j++) {
			printf_s("%c", cars[i].country[j]);
		}
		printf_s("%d)", i + 1);
		printf("Year: %d \n", cars[i].year);

		printf_s("%d)", i + 1);
		printf("Max Speed: %d \n", cars[i].max_speed);

		printf_s("%d)", i + 1);
		color(cars[i].color);
		
		printf("\n");
		printf("- - - - - - - - - - -\n");
		printf("\n");
		
	}
}

void sorting_mark(car*cars,int size)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (strcmp(cars[i].mark, cars[j].mark) > 0) {
				char* tmp = cars[i].mark;
				cars[i].mark = cars[j].mark;
				cars[j].mark = tmp;

				tmp = cars[i].country;
				cars[i].country = cars[j].country;
				cars[j].country = tmp;

				int tmpi = cars[i].year;
				cars[i].year = cars[j].year;
				cars[j].year = tmpi;

				int tmpi1 = cars[i].max_speed;
				cars[i].max_speed = cars[j].max_speed;
				cars[j].max_speed = tmpi1;
			}
		}
	}
	showing(cars, size);
}

void sorting_country(car* cars, int size)
{
    int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (strcmp(cars[i].country, cars[j].country) > 0) {
				char* tmp = cars[i].mark;
				cars[i].mark = cars[j].mark;
				cars[j].mark = tmp;

				tmp = cars[i].country;
				cars[i].country = cars[j].country;
				cars[j].country = tmp;

				int tmpi = cars[i].year;
				cars[i].year = cars[j].year;
				cars[j].year = tmpi;

				int tmpi1 = cars[i].max_speed;
				cars[i].max_speed = cars[j].max_speed;
				cars[j].max_speed = tmpi1;

				int tmpi2 = cars[i].color;
				cars[i].color = cars[j].color;
				cars[j].color = tmpi2;
			}
		}
	}
	showing(cars, size);
}

void sorting_year(car* cars,int size)
{
	for (int i = 0; i < size; i++) {
		int p = i;
		while (p > 0 && cars[p].year < cars[p - 1].year) {
			char* tmp = cars[p].mark;
			cars[p].mark = cars[p - 1].mark;
			cars[p - 1].mark = tmp;

			tmp = cars[p].country;
			cars[p].country = cars[p - 1].country;
			cars[p - 1].country = tmp;

			int tmpi = cars[p].year;
			cars[p].year = cars[p - 1].year;
			cars[p - 1].year = tmpi;

			int tmpi1 = cars[p].max_speed;
			cars[p].max_speed = cars[p-1].max_speed;
			cars[p-1].max_speed = tmpi1;

			int tmpi2 = cars[p].color;
			cars[p].color = cars[p - 1].color;
			cars[p - 1].color = tmpi2;
		}
	}
	showing(cars, size);
}

void sorting_max_speed(car* cars, int size)
{
	for (int i = 0; i < size; i++) {
		int p = i;
		while (p > 0 && cars[p].max_speed < cars[p - 1].max_speed) {
			char* tmp = cars[p].mark;
			cars[p].mark = cars[p - 1].mark;
			cars[p - 1].mark = tmp;

			tmp = cars[p].country;
			cars[p].country = cars[p - 1].country;
			cars[p - 1].country = tmp;

			int tmpi = cars[p].year;
			cars[p].year = cars[p - 1].year;
			cars[p - 1].year = tmpi;
			

			int tmpi1 = cars[p].max_speed;
			cars[p].max_speed = cars[p - 1].max_speed;
			cars[p - 1].max_speed = tmpi1;

			int tmpi2 = cars[p].color;
			cars[p].color = cars[p - 1].color;
			cars[p - 1].color = tmpi2;
		}
	}
	showing(cars, size);
}

void sorting_color(car* cars, int size)
{
	for (int i = 0; i < size; i++) {
		int p = i;
		while (p > 0 && cars[p].color < cars[p - 1].color) {
			char* tmp = cars[p].mark;
			cars[p].mark = cars[p - 1].mark;
			cars[p - 1].mark = tmp;

			tmp = cars[p].country;
			cars[p].country = cars[p - 1].country;
			cars[p - 1].country = tmp;

			int tmpi = cars[p].year;
			cars[p].year = cars[p - 1].year;
			cars[p - 1].year = tmpi;


			int tmpi1 = cars[p].max_speed;
			cars[p].max_speed = cars[p - 1].max_speed;
			cars[p - 1].max_speed = tmpi1;

			int tmpi2 = cars[p].color;
			cars[p].color = cars[p - 1].color;
			cars[p - 1].color = tmpi2;
		}
	}
	showing(cars, size);
}

void deleting(car*cars, int *size)
{
	printf("Enter the number of object, that you want to delete:\n");
	int oper = 0;
	while (oper > (* size) || oper <= 0) {
		printf("Error, you can not delete structure that you have not\n");
		oper = input_size();
		oper = oper - 1;
	}
	for (int i = 0; i < (*size); i++)
	{
		char* tmp = cars[oper].mark;
		cars[oper].mark = cars[oper + 1].mark;
		cars[oper + 1].mark = tmp;

		tmp = cars[oper].country;
		cars[oper].country = cars[oper + 1].country;
		cars[oper + 1].country = tmp;

		int tmpi = cars[oper].year;
		cars[oper].year = cars[oper + 1].year;
		cars[oper + 1].year = tmpi;


		int tmpi1 = cars[oper].max_speed;
		cars[oper].max_speed = cars[oper + 1].max_speed;
		cars[oper + 1].max_speed = tmpi1;

		int tmpi2 = cars[oper].color;
		cars[oper].color = cars[oper + 1].color;
		cars[oper + 1].color = tmpi2;
	}
	(*size)--;
}

void freeshka(car* cars, int size) {
	for (int i = 0; i < size; i++) {
		free(cars[i].mark);
		free(cars[i].country);
	}
	free(cars);
}
