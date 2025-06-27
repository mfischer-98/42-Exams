#include <unistd.h>

/* int match(char *first, char a, char *second, char b)
{
	while ()
} */

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int k;
	int	is_double;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			is_double = 0;
			k = 0; //k sempre volta a 0 pra eu ver se a letra ja esteve em algum lugar da string 1
			while (k < i) //faco um ciclo em argv1 pra ver se há letras repetidas
			{
				if (argv[1][k] == argv[1][i])
				{
					is_double = 1;
					break ;
				}
				k++;
			}
			if (!is_double)
			{
				j = 0;
				while (argv[2][j])
				{
					if ((argv[1][i] == argv [2][j]))
					{
						write(1, &argv[1][i], 1);
						break ;
					}
					j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
}