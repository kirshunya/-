#include <stdio.h>
int main()
{
	int n, a, b, c, j, d, i, f;
	d = 2;
	i = 1;
	f = 1;
	for (n = 123; n < 789; n++)
	{
		c = n % 10;
		b = n % 100;
		b = (b - c) / 10;
		a = n % 1000;
		a = (a - b - c) / 100;
		for (j = 11; j < 28; j++) {
			if (j * j == n && a < b && b < c) {
				printf("This number is: %i\n", n);
				
				return 0;

			}
			

		}
	}
	
}