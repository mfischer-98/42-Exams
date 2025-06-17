#include <unistd.h>

char	ft_mirror(char c)
{
	if (c >= 'a' && c <= 'z')
		c = (122 - c) + 97;
	else if (c >= 'A' && c <= 'Z')
		c = (90 - c) + 65;
	return (c);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			argv[1][i] = ft_mirror(argv[1][i]);
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}