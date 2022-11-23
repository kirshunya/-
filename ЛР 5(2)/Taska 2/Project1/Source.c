#include <stdlib.h> 
#include <stdio.h> 
#include "lib.h"
void main()
{
	int size;
	int** mas = input(&size);
	output(mas, size);
	delete(mas, size);
}