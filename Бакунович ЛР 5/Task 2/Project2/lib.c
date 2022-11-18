#include <stdlib.h> 
#include <stdio.h> 
#include <process.h>
#include "lib.h"
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
int** input(int* N)
{
    int i, j;
    int** mas;
    mas = (int**)calloc(1, sizeof(int*));
    mas[0] = (int*)calloc(1, sizeof(int));
    i = 0;
    printf("Input %d line\n", i);
    printf("for stop press any not number\n");
    while (getchar() != 'n')
    {
        j = 0;
        while (scanf_s("%d",&mas[i][j])&& mas[i][j]!=0)
        {
            j++;
            mas[i] = (int*)realloc(mas[i], (j + 1) * sizeof(int));
        }
        mas[i][j] = 0;
        i++;
        mas = (int**)realloc(mas, (i + 1) * sizeof(int*));
        mas[i] = (int*)calloc(1, sizeof(int));
        printf("Input %d line\n", i);
        printf("for stop press any not number\n");
        //printf("Do you want to enter one more line? (y/n)\n");
        rewind(stdin);

    }
    *N = i;
    return mas;
}
void output(int** mas, int N)
{
    for (int i = 0; i < N; i++)
    {
        int j = 0;
        while (mas[i][j]!=0)
        {
            printf("%d\t",mas[i][j]);
            j++;
        }
        printf("\n");
    }
}
void delete(int** mas,int N)
{
    int min=0;
    int M = N;
    for (int i = 0; i < M; i++)
    {
       
        if (i%2!=0||i==1)
        {
                min = mas[i][0];
                for (int j = 0; j < N; j++)
                {
                    if (min > mas[i][j])
                    {
                        min = mas[i][j];
                    }
                }

                int j = 0, amount = 0;
                while (mas[i][j] != 0)
                {
                    amount++; j++;
                }
                for (j = 0; j < amount; j++)
                {
                    if (mas[i][j]==min)
                    {
                        for (int k = j; k < amount; k++)
                        mas[i][k] = mas[i][k + 1];
                        mas[i] = (int*)realloc(mas[i], amount * sizeof(int));
                        amount--;
                        j--;
                    }
                }

            
        }
    }
 printf("New array:\n");
 output(mas,N);
}
void third()
{
    int size;
    //printf("Enter the number of rows :\n");
   // input_size(&size);
    int i,j = 0;
    int** mas = input(&size);
    output(mas, size);
   delete( mas, size);

}
