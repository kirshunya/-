#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    int size = argc - 1;
    char** str = (char**)calloc(argc - 1, sizeof(char*));
    for (int i = 1; i < argc; i++)
        str[i - 1] = argv[i];
    int* arrsize = (int*)calloc(argc - 1, sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        rewind(stdin);
        arrsize[i] = max_length(str[i]);
    }
    printf("Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("\n%d\n", arrsize[i]);
        printf("%s", str[i]);
    }
    printf("\n");
    quick(arrsize, str, 0, size);
    printf("Sorted Array:\n");
    int j = 0;
    for (int i = size-1; i >=0; i--)
    {
        printf("%d  ", arrsize[i]);
        printf("%s", str[i]);
        printf("\n");
    }
}
int length_str(char*str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        if (str[len] < 0){
            return(-1);
        }
        len++;
    }
    return len;
}
int max_length(char*str)
{
    int len = length_str(str);
    if (len == (-1)) {
        return(-1);
    }
    int j = 0;
    int check = 0, maxlen = 0, ans = 0;
    while ((str[j] <= 122 && str[j] >= 97) || (str[j] <= 90 && str[j] >= 65))
    {
        maxlen++;
        j++;
    }
    if (maxlen > ans)
    {
        ans = maxlen;
    }
    maxlen = 0;
    for (int i = 0; i < len - 1; i++)
    {
        check = 0;
        if ((str[j] <= 122 && str[j] >= 97) || (str[j] <= 90 && str[j] >= 65))
        {
            j = i + 1;
            while ((str[j] <= 122 && str[j] >= 97) || (str[j] <= 90 && str[j] >= 65))
            {
                j++;
                maxlen++;
            }
            if (maxlen > ans)
            {
                ans = maxlen;
            }
            maxlen = 0;
        }
    }
    return ans;
}
void swap(int*n1, int*n2)
{
    int* swap = *n1;
    *n1 = *n2;
    *n2 = swap;
}
void charswap(char**c1,char**c2)
{
    char* swap = *c1;
    *c1 = *c2;
    *c2 = swap;
}
int partition(int*list,char**str,int start,int pivot)
{
    int i = start;
    while (i < pivot)
    {
        if (list[i] > list[pivot] && i == pivot - 1)
        {
            swap(&list[i], &list[pivot]);
            charswap(&str[i], &str[pivot]);
            pivot--;
        }
        else if (list[i] > list[pivot])
        {
            swap(&list[pivot - 1], &list[pivot]);
            swap(&list[i], &list[pivot]);

            charswap(&str[pivot - 1], &str[pivot]);
            charswap(&str[i], &str[pivot]);
            pivot--;
        }
        else i++;
    }
    return pivot;
}
int quick(int*list,char**str,int start,int end)
{
    if(start<end){
        int pivot = partition(list, str, start, end);
        quick(list, str, start, pivot - 1);
        quick(list, str, pivot + 1, end);
    }
    return end;
}
