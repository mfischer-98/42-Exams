/* #include <stdio.h> */
#include <stdlib.h>

int	ft_size(int nbr)
{
	int	len = 0;

	if (nbr < 0)
	{
		len ++;
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	if (nbr < 10)
		len++;
	return (len);
}

char	*ft_itoa(int nbr)
{
	int	size = ft_size(nbr);
	long	num;
	char	*str;
	int		i = 0;

	num = nbr;
	str = malloc (sizeof (char) * (size + 1));
	if (!str)
		return (NULL);
	i = size - 1;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num >= 10)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	str[i] = num + '0';
	str[size] = '\0';
	return (str);
}

/* int	main(int argc, char **argv)
{
	int num = atoi(argv[1]);

	if (argc == 2)
		printf("%s", ft_itoa(num));
	//printf("%d", ft_size(-202121));
} */