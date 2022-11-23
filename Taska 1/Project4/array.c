#include <stdlib.h> 
#include <stdio.h> 
#include "array.h"
void input_size(int* size,int*num)
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
    *num = a;
}
int* memory(int size)
{
    int* mass = (int*)malloc(size * sizeof(int));
    
    return mass;
}
void input_array(int* mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Input an arr element:\n");
        scanf_s("%d", &mass[i]);
        while (getchar() != '\n')
        {
            rewind(stdin);
            printf("\nErorr: please enter correct data:\n");
            scanf_s("%d", &mass[i]);
        }
    }
}
void delete(int* size, int** mass, int* fl)
{
    int flag = 0;
    for (int i = 0; i < (*size); i++)
    {
        printf("%d\n", (*size));
        if ((*mass)[i] < 0)
        {
            flag++;
            for (int k = i; k < (*size) - 1; k++)
            {
                (*mass)[k] = (*mass)[k + 1];
            }
            (*mass) = (int*)realloc((*mass), ((*size) - 1) * sizeof(int));
            (*size)--;
            i--;
        }
    }
    *fl = flag;
}
void output_array(int* mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",mass[i]);
    }
}
void check(int num,int fl,int*mass,int size)
{
    if (fl == num)
    {
        printf("\nAll elements are negative\n");
    }
    if (fl < num)
    {
        if (fl <= 0)
        {
            printf("\nThere are no negative elements here\n");
        }
        else
        {
            printf("\nNew arr:\n");
            output_array(mass, size);
        }
    }
   
}