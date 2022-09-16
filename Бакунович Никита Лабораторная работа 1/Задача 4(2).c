#include <stdio.h>

int main()
{
    char* month[] = { "Winter","Winter","Spring","Spring","Spring","Summer","Summer", "Summer", "Autumn", "Autumn","Autumn", "Winter" }; //массив с месяцами
    int n;
    printf("Enter the month number: \n"); //ввод ноиера месяца
    scanf_s("%d", &n);
    if (n > 0 && n < 13) //проверка номера месяца
        printf("You enter %d - %s", n, month[n]);
    else
        printf("Wrong number (n can not be > 12"); //конец программы , если пользователь ввел число больше 12


    return 0;
}