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
    printf("for transition on the next line press 0\n");
    printf("and for stop press 'n' 0\n");
    while (getchar() != 'n')
    {
        j = 0;
        while (scanf_s("%d", &mas[i][j]) && mas[i][j] != 0)
        {
            j++;
            mas[i] = (int*)realloc(mas[i], (j + 1) * sizeof(int));
        }
        mas[i][j] = 0;
        i++;
        mas = (int**)realloc(mas, (i + 1) * sizeof(int*));
        mas[i] = (int*)calloc(1,sizeof(int));
        printf("Input %d line\n", i);
        printf("for stop press any not number\n");
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
            printf("%d\t", mas[i][j]);
            j++;
        }
        printf("\n");
    }
}
void delete(int** mas, int N)
{
    int min = 0;
    int n = N;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0 || i == 1)
        {
            min = mas[i][0];
            int m=0;
            while (mas[i][m] != 0)
            {
                m++;
                if (min > mas[i][m])
                {
                    min = mas[i][m];
                }
            }
            int j = 0;int cntr = 0;
            while (mas[i][j] != 0)
            {
                cntr++; j++;
            }
            for (j = 0; j < cntr; j++)
            {
                if (mas[i][j] == min)
                {
                    for (int k = j; k < cntr; k++)
                        mas[i][k] = mas[i][k + 1];
                    mas[i] = (int*)realloc(mas[i], cntr * sizeof(int));
                    cntr--;
                    j--;
                }
            }
        }
    }
    printf("New array:\n");
    output(mas,N);
    free(mas);
}
