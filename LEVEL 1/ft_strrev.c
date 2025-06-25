char	*ft_strrev(char *str)
{
	int	len;
	int	i;
	char	temp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len--;
	while (i < len)
	{
		temp = str[i]; // coloco primeira letra no temp
		str[i] = str[len]; // coloco ultima letra na 1a posicao
		str[len] = temp; // ultima letra fica igual a primeira
		i++;
		len--; //corre ate o meio da palavra e troco 1 e ultima a cada ciclo
	}
	return (str);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s", ft_strrev(argv[1]));
	} 
}