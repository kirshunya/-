#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Source.h"
void input_size(int* size)
{
    long long a;
    scanf_s("%10lld", &a);
    while (getchar() != '\n' || a < 1 || a > 4)
    {
        rewind(stdin);
        printf("\nErorr: please try again:\n");
        scanf_s("%10lld", &a);
    }
    *size = a;
}

Pixel median(Pixel* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].red > arr[j].red) {
                Pixel temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr[n / 2];
}
