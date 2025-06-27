#include <unistd.h>

void ft_rcap(char *str)
{
	int i = 0;

	while(str[i])
	{
		if((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' '))
			str[i] -= 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i + 1] != ' '))
			str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 1;

	if (ac >= 2)
	{
		while (av[i])
		{
			ft_rcap(av[i]);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}