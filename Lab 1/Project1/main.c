#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Source.h"
#define scanf scanf_s
void menu()
{
	printf("Task menu:\n");
	printf("1)Task condition\n");
	printf("2)Creating a Structure\n3)Showing a structure\n4)Deleting\n5)Sorting\n");
	printf("6)Exit\n");
}

void task()
{
	printf("1. Implement a function to create an array of structures.\n");
	printf("2. Implement a function for displaying an array of structures on the screen.\n");
	printf("3. Implement a function to initialize an instance of the structure.\n");
	printf("4. Implement array sorting functions for each field of the structure. (For example, you can sort students first by date of birth, then change your mind and sort by average score).\n");
	printf("5. Implement a menu to test the functionality.\n");
	printf("6. Functions should not be bound to a specific array: such must be passed as an argument.\n");
	printf("7. Use enum as the type of one of the fields of the structure (for example, for color).\n");
	printf("8. Implement a function to remove a structure from an array.\n");
	printf("9. Implement sorting by two fields at the same time. (For example, sort cars by color, so that all cars of the same color go in the order of the year of manufacture).\n");
}

int main(car* cars)
{
	int size = 0;
	int oper = 0;
	while (oper != 6) {
		menu();
		oper = input_oper();
		system("cls");
		switch (oper)
		{
		case 1:
		{
			task();
			break;
		}
		case 2:
		{
			cars = creating_struct(&size);
			break;
			
		}
		case 3:
		{
			printf("The structure:\n");
			printf("\n");
			showing(cars, size);
			break;
		}
		case 4:
		{
			printf("Cooming soon...."); 
			//deleting(cars,&size);
			break;
		}
		case 5:
		{
			int op = 0;
			printf("Sorting menu:\n1)Sortnig Mark\n2)Sorting Country\n3)Sorting Year\n4)Sorting Max Speed\n5)Sorting Color\n");
			op = input_sorting();
			switch (op)
			{
				case 1:
				{
					sorting_mark(cars, size);
					break;
				}
				case 2:
				{
					sorting_country(cars,size);
					break;
				}
				case 3:
				{
					sorting_year(cars,size);
					break;
				}
				case 4:
				{
					sorting_max_speed(cars, size);
					break;
				}
				case 5:
				{
					sorting_color(cars, size);
					break;
				}
				default:
				{
					printf("\nExit from theese menu\n");
				}
			}
			break;
		}
		case 6:
		{
			printf("Programm closed.\n");
			break;
		}
		default:
		{
			printf("\nExit from theese menu\n");
			freeshka(&cars, size);
		}
		}
		clear_and_stop_console();
	}
}