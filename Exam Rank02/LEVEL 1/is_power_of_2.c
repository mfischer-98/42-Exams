#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	test = 1;

	while (test <= n) //multiplicar teste por 2 e se for =n e potencia de 2
	{
		if (test == n)
			return (1);
		test = test * 2;
	}
	return (0);
}

int	main()
{
	printf("return value: %d\n", is_power_of_2(4));
	return (0);
}