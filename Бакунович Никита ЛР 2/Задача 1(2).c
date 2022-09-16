#include <stdio.h>
int main()
{
	int n,a,s;
	double prc;

	n = 0;
	a = 20000;
	printf("You need :%i \n", a);
	s = 10000;
	printf("Your ammount:%i \n", s);
	prc = 1.03;
	while(s<a) 
	{
		 s=s * prc;
		n = n + 1;
	}
	
	
	printf("Your amount will increase by 2 times after %i  ", n);
	printf("months");

	return 0;
}