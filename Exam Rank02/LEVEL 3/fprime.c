#include <stdio.h>
#include <stdlib.h>

void ft_prime(int n)
{
	int	test = 1;
	int	i = 0;

	if (n == 1)
		printf("1");
	while (test <= n)
	{
		if (n % 2 == 0)
		{
			test *= 2;
			printf("2");
				if (test < n)
					printf("*");
		}
		if (n % 3 == 0)
		{
			test *= 3;
			printf("3");
				if (test < n)
					printf("*");
		}
		if (n % 5 == 0)
		{
			test *= 5;
			printf("5");
				if (test < n)
					printf("*");
		}
		if (n % 7 == 0)
		{
			test *= 7;
			printf("7");
				if (test < n)
					printf("*");
		}		
		if (n % 13 == 0)
		{
			test *= 13;
			printf("13");
				if (test < n)
					printf("*");
		}		
		if (n % 37 == 0)
		{
			test *= 37;
			printf("37");
				if (test < n)
					printf("*");
		}
	}
}


int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_prime(atoi(argv[1]));
	printf("\n");
}