#include <stdio.h>
#include <stdlib.h>
#include <process.h>
int main()
{
	srand(_getpid());
	int array[100] = { 0 };
	int resh, resh1 = 0;
	int sum = 0;
	int i = 0;
	int zero2 = 0;
	int zero1 = -1;
	int pr = 1;
	int j = 1;
	printf("How many numbers do you want ?\n");
	while (scanf_s("%d", &resh) != 1 || resh < 0 || resh > 100 || getchar() != '\n')
	{
		printf("Mistake,try again\n");
		rewind(stdin);
	}
	printf("Do you want to generate arrayes?(1-yes)\n");
	while (scanf_s("%d", &resh1) != 1 || resh1 < 0 || resh1 > 100 || getchar() != '\n' || resh1>10)
	{
		printf("Mistake,try again\n");
		rewind(stdin);
	}
	if (resh1 == 1)
	{
		int i = 1;
		for (i = 1; i <= resh; i++)
		{
			array[i] = rand() % 10-5 ;
			printf("Array element:%d\n", array[i]);
			if (i % 2 == 0)
			{
				pr = pr * array[i];
			}

			if (array[i] == 0)
			{
				if (zero1 != -1)
				{
					zero2 = i;
				}
				else
				{
					zero1 = i;
				}
			}
			//printf("%d\n", zero1);
		}

		for (zero1; zero1 < zero2; zero1++)
		{
			rewind(stdin);
			sum = sum + array[zero1];
		}
		if (zero1 == 0)
		{
			rewind(stdin);
			printf("The summ of array elements:0\n");
		}
		else printf("The summ of array elements:%i\n", sum);
		{
			if (sum == 0)
			{
				rewind(stdin);
				printf("The summ of array elements:0\n");
			}
		}
		printf("The product of array elements:%i\n", pr);
	}

	else
	{
		for (int j = 1; j <= resh; j++)
		{
			printf("Enter number %d:\n", j);
			while (scanf_s("%d", &array[j]) != 1 || getchar() != '\n')
			{
				printf("Wrong imput. Try again\n");
				rewind(stdin);
			}
			if (j % 2 == 0)
			{
				pr = pr * array[j];
			}
			if (array[j] == 0)
			{
				if (zero1 != -1)
				{
					zero2 = j;

				}
				else
				{
					zero1 = j;
					j = zero1;

				}
			}

		}
		for (zero1; zero1 < zero2; zero1++)
		{
			rewind(stdin);
			sum = sum + array[zero1];
		}
		if (zero1 == 0)
		{
			rewind(stdin);
			printf("The summ of array elements:0\n");
		}
		else printf("The summ of array elements:%i\n", sum);
		{
			if (sum == 0)
			{
				rewind(stdin);
				printf("The summ of array elements:0\n");
			}
		}
		rewind(stdin);

		printf("The product of array elements:%i\n", pr);
		//printf("The summ of array elements:%i\n", sum);
		return 0;


	}
}