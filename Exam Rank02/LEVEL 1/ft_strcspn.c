#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while(s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		printf("Mine: %ld", ft_strcspn(argv[1], argv[2]));
		printf("\nOriginal: %ld", strcspn(argv[1], argv[2]));
	}
}