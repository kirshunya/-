
#include <stdio.h>

int main(void)
{
    int a, b, c, n;
    a = 0;
    b = 0;
    c = 0;
    n = 0;
    printf("Enter A length :\n");
    scanf_s("%d", &a);
    printf("Enter B length:\n");
    scanf_s("%d", &b);
    if (b > a) {
        printf("B cannot be more than A by condition\n");
        return 0;
    }
    for (; a > b;) {
        a = a - b;
        c = c + 1;
        
    }
    printf("The maximum number of segments B on segment A is equal to :%i\n", c);

    return 0;
}
