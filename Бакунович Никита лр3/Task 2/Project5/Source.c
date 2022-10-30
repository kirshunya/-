#include <stdio.h>
#include <stdlib.h>
#include <process.h>
int main()
{
	int resh1, resh2, counter1,counter3 = 0;
	int massiv[100] = { 0 };
	srand(_getpid());
	printf("How many numbers do you want?(max 50)\n");
		while (scanf_s("%d", &resh1) != 1 || resh1 < 0|| resh1>100||getchar()!='\n'|| resh1 == (-0))
		{
			printf("Wrong number, try again\n");
			rewind(stdin);
		}
	printf("Do you want to randomize your numbers?(1- yes)(2-10-no)\n ");
	while (scanf_s("%d", &resh2) != 1 || resh2 < 0 || resh2 >= 100 || getchar() != '\n'||resh2>10)
	{
		printf("Wrong number, try again\n");
		rewind(stdin);
	}
	if (resh2 == 1)
	{
		for (int counter2 = 0; counter2 <= resh1; counter2++)
		{
			massiv[counter2] = rand() % 200 - 50;
		}
		for (int m = 0; m < resh1; m++)
		{
			if (massiv[m] < 0)
			{
				resh1++;
				for (int l = resh1; l > m; l--)
				{
					massiv[l] = massiv[l - 1];
				}
				m++;
			}
		}
		for (int m = 0; m < resh1; m++)
		{
			printf("Array of element:%d\n", massiv[m]);
		}
	}
	else
	{
		for (int counter3 = 1; counter3 <= resh1; counter3++)
		{
			printf("Enter number %d:\n", counter3);
			while (scanf_s("%d", &massiv[counter3]) != 1|| getchar() != '\n')
			{
				printf("Wrong imput. Try again\n");
				rewind(stdin);
			}
		}
	}
	for (int m = 0; m < resh1; m++)
	{
		if (massiv[m] < 0)
		{
			resh1++;
			for (int l = resh1; l > m; l--)
			{
				massiv[l] = massiv[l - 1];
			}
			m++;
		}
	}
	for (int m = 0; m < resh1; m++)
	{
		printf("%d\n", massiv[m]);
	}
	return 0;
}
