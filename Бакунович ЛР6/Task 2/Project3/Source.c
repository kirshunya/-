#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include "lib.h"
void main()
{
	int left = 0;
	int row = 0;
	int col = 0;
	int oper = 0;
	input_size_row(&row);
	input_size_coll(&col);
	int right = col-1;
	int** mas = memory(row, col);
	input(row, col, mas);
	sum(row, col, mas);
	output_with_sum(row, col, mas);
	printf("\nChoose:\n1)Quick\n2)Bubble\n");
	input_oper(&oper);
	switch (oper)
	{
		case 1:
		{
			printf("Column sorting by Hoare method\n");
			clock_t begin = clock();
			quick_sort(mas,left,right, row);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			output_without_sum(row, col, mas);
			printf("\n");
			printf("time is %f sec\n", time_spent);
			break;
		}
		case 2:
		{
			printf("Column sorting by bubles method\n");
			clock_t begin = clock();
			bubble_sort(mas, col, row, col);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			output_without_sum(row, col, mas);
			printf("\n");
			printf("time is %f sec\n", time_spent);
			break;
		}
	}
}