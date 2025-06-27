#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	res = 0;

	if (*str == '-')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int is_prime(int n)
{
	int test = 2; //starts at 2 because every number /2 is not prime
	
	if (n < 2)
		return (0); //firts prime nbr is 3

	while (test * test <= n) //testing if i can divide number by anything but himself
	{
		if (n % test == 0)
			return (0);
		test++;
	}
	return (1);
}
void	ft_put_char(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_put_char(n % 10 + '0');
}

int main(int ac, char **av)
{
	int sum = 0;

	if (ac == 2)
	{
		int n = ft_atoi(av[1]);
		printf("n = %d\n", n);
		while (n > 1)
		{
			if(is_prime(n)) //vejo se numero e primo, se sim, coloco na sum ate n
				sum += n;
			n--;
		}
		printf("sum = %d\n", sum);
		ft_putnbr(sum);
	}
	write(1, "0\n", 2);
}