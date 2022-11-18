#include <stdlib.h> 
#include <stdio.h> 
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
void input_array(int* mas, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Input an arr element:\n");
        scanf_s("%d", &mas[i]);
        while (getchar() != '\n')
        {
            rewind(stdin);
            printf("\nErorr: please enter correct data:\n");
            scanf_s("%d", &mas[i]);
        }
    }
}
void output_array(int* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}
void first()
{
    int size;
    printf("Enter the number of elements in the arr:\n");
    input_size(&size);
    int* mass = (int*)malloc(size * sizeof(int));
    input_array(mass, size);
    int flag = 0;
    int Num = size;
    for (int i = 0; i < size; i++)
    {
        if (mass[i] < 0)
        {
            flag++;
            for (int k = i; k < (size - 1); k++)
            {
                mass[k] = mass[k + 1];
            }
            mass = (int*)realloc(mass, (size - 1) * sizeof(int));
            size--;
            i--;
        }
    }
    if (flag == Num)
    {
        printf("\nAll elements are negative\n");
    }
    if (flag>0&&flag<Num)
    {
        printf("\nNew arr:\n");
        output_array(mass, size);
    }
    if(flag<=0)
    {
        printf("\nThere are no negative elements here\n");
    }
    
}