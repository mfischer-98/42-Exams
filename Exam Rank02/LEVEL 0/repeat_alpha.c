#include <unistd.h>

int	ft_count(char c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 96;
		return (c);
	}
	else if (c >= 65 && c <= 90)
	{
		c = c - 64;
		return (c);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			count = ft_count(argv[1][i]);
			while (count > 0)
			{
				write(1, &argv[1][i], 1);
				count--;
			}	
			i++;
		}
	}
	else
		write(1, "\n", 1);
}