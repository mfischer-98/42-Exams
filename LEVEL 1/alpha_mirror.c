#include <unistd.h>
#include <unistd.h>

void	ft_mirror(char c)
{
	if(c >= 'a' && c <= 'z')
		c = 122 - (c - 97);
	else if(c >= 'A' && c <= 'Z')
		c = 90 - (c - 65);
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			ft_mirror(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}