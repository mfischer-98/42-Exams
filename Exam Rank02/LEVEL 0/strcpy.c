#include <unistd.h>
#include <stdio.h>
#include <strings.h>

char *ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

int	main()
{
	char src[] = "lets goo";
	char dest[] = "";

	ft_strcpy(dest, src);
	printf("%s", dest);
}