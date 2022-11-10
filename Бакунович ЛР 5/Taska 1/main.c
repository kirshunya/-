#define _CRT_SECURE_NO_WARNINGS
#include "library.h"
void main()
{
	int flag,n=0;
	int *mas;
	printf("Input size array: ");
	input(&n);
	int N=n;
	mas = (int*)malloc(n * sizeof(int));
	input_array(n, mas);
for (int i = 0; i < n; i++)	
{
		for (int j = i + 1; j < n+1; j++)
		{
			 if (mas[i] <0)  
			 { 
                flag = 1; 
                for (int k = j; k < N; k++) 
                    mas[k-1] = mas[k]; 
                mas = (int*)realloc(mas, (n - 1) * sizeof(int));//перевыделяет память(когда ее нужно изменить 
                n--; 
                j--; 
             } 
		}
	}
output_array(n,mas,flag);
} 