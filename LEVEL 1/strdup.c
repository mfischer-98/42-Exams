#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = src;
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s", ft_strdup(argv[1]));
}