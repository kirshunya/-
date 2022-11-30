#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h> 
#include "lib.h"
void main()
{
	double time_spent1 = 0.0;
	double time_spent2 = 0.0;
	double time_spent3 = 0.0;
	double time_spent4 = 0.0;
	int size,strt,end,cnt,oper = 0;
	printf("Enter the size of array\n");
	input_size(&size);
	int* mas = memory(size);
	int* temp =memory(size);
	input_array(size,mas);
	min_search(size, mas, &strt, &end);
	search(mas,strt,end,temp,&cnt);
	output_array(mas,size);
	printf("\nChoose:\n1)Quick\n2)Bubble\n");
	input_oper(&oper);
	if (end != 0)
	{
		switch(oper)
		{
			case 1:
				{
				clock_t begin1 = clock();
				sort_second(temp, size, strt, end, mas, cnt);
				clock_t end1 = clock();
				time_spent1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;
				printf("\n");
				printf("Assorted array(ascending insertion method):\n");
				output_array(mas, size);
				printf("\n");
				printf("The elapsed time is %f seconds", time_spent1);
				printf("\n");
				clock_t begin2 = clock();
				reverse_sorting(temp, size, strt, end, mas, cnt);
				clock_t end2 = clock();
				time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
				printf("Assorted array(the method of inserts in descending order):\n");
				output_array(mas, size);
				printf("\n");
				printf("The elapsed time is %f seconds", time_spent2);
				printf("\n");
				}
				break;
			case 2:
				{
				clock_t begin3 = clock();
				bubble(mas, size, strt, end, temp,cnt);
				printf("Assorted array(the ^bubble method^):\n");
				output_array(mas, size);
				clock_t end3 = clock();
				time_spent3 += (double)(end3 - begin3) / CLOCKS_PER_SEC;
				printf("\n");
				printf("The elapsed time is %f seconds", time_spent3);
				printf("\n");
				clock_t begin4 = clock();
				bubble_reverse(mas, size, strt, end, temp, cnt);
				output_array(mas, size);
				clock_t end4 = clock();
				time_spent4 += (double)(end4 - begin4) / CLOCKS_PER_SEC;
				printf("\n");
				printf("The elapsed time is %f seconds", time_spent3);
				printf("\n");
				}
				break;
		}
	}
	else
	{
		printf("\n");
		printf("There is no 2 minimum elements \n");
	}
}