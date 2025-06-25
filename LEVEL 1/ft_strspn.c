#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while(s[i])
	{
		j = 0;
		count = 0;
		while (accept[j]) 
		{
			if (s[i] == accept[j]) //se forem iguais quero contar +1
				count++;
			j++; //se nunca forem iguais count = 0, se forem o i conta quantas vezes
		}
		if (count == 0)
			return (i);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Mine: %lu", ft_strspn(argv[1], argv[2]));
		printf("\nOG: %lu", strspn(argv[1], argv[2]));
	}
}