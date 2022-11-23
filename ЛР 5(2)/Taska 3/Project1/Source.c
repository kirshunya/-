#include <stdio.h>
#include <stdlib.h>
#include "array.h"
void main()
{
    int size;
    printf("Enter the size of matrix:\n");
    input_size(&size);
    int** mas = memory(size);
    input_array(mas, size);
    output_array(mas, size);
    cycle(&mas,size);
    printf("\n");
    printf("New array:\n");
    output_array(mas, size);
	free(mas);
}