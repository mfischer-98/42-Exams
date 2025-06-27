#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	if (argc == 2)
	{
		while (argv[1][i]) //end of string
			i++;
		i--;
		while (argv[1][i] == ' ') //skip final spaces
			i--;
		end = i;
		while (argv[1][i] > 32) //find start of last word
			i--;
		i++;
		while (i <= end) //print word
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}