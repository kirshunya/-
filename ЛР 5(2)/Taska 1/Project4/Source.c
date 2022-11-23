#include <stdlib.h> 
#include <stdio.h> 
#include "array.h"
void main()
{
	int size =0;
	int fl = 0;
	int num = 0;
	printf("Enter the number of elements in the arr:\n");
	input_size(&size,&num);
	int* mass = memory(size);
	input_array(mass,size);
	delete(&size,&mass,&fl);
	check(num,fl,mass,size);
	free(mass);
}