#include <unistd.h>

int	ft_atoi(char *n)
{
	int	res;

	res = 0;
	while (*n && *n >= '0' && *n <= '9')
	{
		res = res * 10 + (*n - '0');
		n++;
	}
	return (res);
}

void ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = n % 10 + '0';
	write(1, &c, 1);
}


int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
	if (argc == 2)
	{
		int	n = ft_atoi(argv[1]);
		
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(n * i);
			write(1, "\n", 1);
			i++;
		}
	}
}