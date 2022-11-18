#include <stdio.h>
#include <stdlib.h>
#include "array.h"
void input_size(int* size)
{
    long long a;
    scanf_s("%10lld", &a);
    while (getchar() != '\n' || a < 1 || a != (int)a)
    {
        rewind(stdin);
        printf("\nErorr: please try again:\n");
        scanf_s("%10lld", &a);
    }
    *size = a;
}
void input_array(int** mas, int N)
{
    for (int i = 0; i < N; i++)
    {
        for(int j=0;j<N;j++)
        { 
            printf("Input an arr element [%d] [%d]:\n",i,j);
            scanf_s("%10d", &mas[i][j]);
            while (getchar() != '\n')
            {
               rewind(stdin);
               printf("\nErorr: please enter correct data:\n");
               scanf_s("%10d", &mas[i][j]);
            }
        }
    }
}

void second()
{
    int max;
    int size;
    int **mas;
    printf("Enter the size of matrix:\n");
    input_size(&size);
    mas = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        mas[i] = (int*)malloc(size * sizeof(int));
    }
    input_array(mas,size);
    output_array(mas,size);
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i <size; i++)
        {
            if (i = size - 1)
            {
                max=mas[i][j];
            }
            for (int k = size-1; k >0; k--)
            {
                mas[k][j] = mas[k-1][j];
            }
            mas[0][j] = max;
        }
    }
    printf("\n");
    printf("New array:\n");
    output_array(mas, size);
}
void output_array(int** mas, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t",mas[i][j]);
            
        }
        printf("\n");
    }
}

