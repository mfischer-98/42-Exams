#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			neg;
	long int	res;

	res = 0;
	neg = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}	
	return (res * neg);
}

#include <stdlib.h>
int	main(int argc, char **argv)
{
	int	nbr;

	nbr = 0;
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		printf("%d", nbr);
		printf("\n%d", atoi(argv[1]));
	}	
}