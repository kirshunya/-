#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int j, j2 ,resh1,resh2,counter1,randnumb= 0;
    int massiv1[100] = { 0 };
    int massiv2[100] = { 0 };
    int massiv3[100] = { 0 };
    srand(time(NULL));
    printf("How many numbers do you want?\n");
    while (scanf_s("%d", &resh1) != 1 || resh1 < 0 || resh1 > 100 || getchar() != '\n'|| resh1 == (-0))
    {
        printf("Wrong number, try again\n");
        rewind(stdin);
    }
    j = resh1;
    j2 = resh1*2;
    printf("Do you want to randomize your numbers?(1- yes)\n ");
    while (scanf_s("%d", &resh2) != 1 || resh2 < 0 || resh2 >= 100 || getchar() != '\n')
    {
        printf("Wrong number, try again\n");
        rewind(stdin);
    }
    if (resh2 == 1)
    {
        for (int counter2 = 0; counter2 < resh1; counter2++)
        {
            massiv1[counter2] = rand() % 10 ;
            massiv2[counter2] = rand() % 10 ;
            printf("First massiv:%d\n", massiv1[counter2]);
            printf("Second massiv:%d\n", massiv2[counter2]);
            massiv3[counter2]=massiv1[counter2] ;
            massiv3[counter2 + resh1]=massiv2[counter2];
        }
        while (j >= 0)
        {
            int i = 0;
            while (i < j)
            {
                if (massiv1[i] > massiv1[i + 1])
                {
                    int tmp = massiv1[i];
                    massiv1[i] = massiv1[i + 1];
                    massiv1[i + 1] = tmp;
                }
                if (massiv2[i] < massiv2[i+1])
                {
                    int tmp = massiv2[i+1];
                    massiv2[i+1] = massiv2[i];
                    massiv2[i ] = tmp;
                }
                
         i++;}

   j--;}
        while (j2 >= 0)
        {
            int i = 0;
            while (i < j2)
            {
            
                if (massiv3[i] > massiv3[i + 1])
                {
                    int tmp = massiv3[i];
                    massiv3[i] = massiv3[i + 1];
                    massiv3[i + 1] = tmp;
                }
                i++;
            }

          j2--;
        }
            printf("First sort massiv: \n");
            for (int counter2 = 0; counter2 < resh1; counter2++)
            {
                printf("Sort1: %i\n", massiv1[counter2]);
            }
            printf("Second sort massiv: \n");
            for (int counter2 = 0; counter2 < resh1; counter2++)
            {
                printf("Sort2: %i\n", massiv2[counter2]);
            }
            printf("Third sort massiv: \n");
            for (int counter2 = 0; counter2 < resh1*2; counter2++)
            {
                printf("Sort3: %i\n", massiv3[counter2]);
            }
    }
    else
    {
        for (int counter3 = 0; counter3 < resh1; counter3++)
        {
            printf("Enter number of firts array %d:\n", counter3);
            while (scanf_s("%d", &massiv1[counter3]) != 1|| getchar() != '\n')
            {
                printf("Wrong imput. Try again\n");
                rewind(stdin);
            }
            printf("Enter number of second array %d:\n", counter3);
            while (scanf_s("%d", &massiv2[counter3]) != 1|| getchar() != '\n')
            {
                printf("Wrong imput. Try again\n");
                rewind(stdin);
            }
            massiv3[counter3] = massiv1[counter3];
            massiv3[counter3 + resh1] = massiv2[counter3];
        } 
        while (j >= 0)
        {
            int i = 0;
            while (i < j)
            {
                if (massiv1[i] > massiv1[i + 1])
                {
                    int tmp = massiv1[i];
                    massiv1[i] = massiv1[i + 1];
                    massiv1[i + 1] = tmp;
                }
                if (massiv2[i] < massiv2[i + 1])
                {
                    int tmp = massiv2[i + 1];
                    massiv2[i + 1] = massiv2[i];
                    massiv2[i] = tmp;
                }

                i++;
            }

            j--;
        }
        while (j2 >= 0)
        {
            int i = 0;
            while (i < j2)
            {

                if (massiv3[i] > massiv3[i + 1])
                {
                    int tmp = massiv3[i];
                    massiv3[i] = massiv3[i + 1];
                    massiv3[i + 1] = tmp;
                }
                i++;
            }

            j2--;
        }
        
    
    printf("First sort massiv: \n");
    for (int counter2 = 0; counter2 < resh1; counter2++)
    {
        printf("Sort1: %i\n", massiv1[counter2]);
    }
    printf("Second sort massiv: \n");
    for (int counter2 = 0; counter2 < resh1; counter2++)
    {
        printf("Sort2: %i\n", massiv2[counter2]);
    }
    printf("Third sort massiv: \n");
    for (int counter2 = 0; counter2 < resh1 * 2; counter2++)
    {
        printf("Sort3: %i\n", massiv3[counter2]);
    }
  }
}