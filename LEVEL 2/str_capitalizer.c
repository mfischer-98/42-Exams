#include <unistd.h>

void ft_capt(char *str)
{
	int	i = 0;

	if ((str[i] >= 'a' && str[i] <= 'z') && (i = 0))
		str[i] -= 32;
	while (str[i])
	{

		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' '))
			str[i] -= 32;
		if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i - 1] != ' '))
			str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (argv[i])
		{
			ft_capt(argv[i]);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}