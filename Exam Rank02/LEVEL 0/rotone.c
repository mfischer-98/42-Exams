#include <unistd.h>

int	ft_isalpha(char c)
{
/* 	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0); */
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 'z')
				argv[1][i] = 'a';
			else if (argv[1][i] == 'Z')
				argv[1][i] = 'A';
			else if (ft_isalpha(argv[1][i]))
				argv[1][i] += 1;	
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}