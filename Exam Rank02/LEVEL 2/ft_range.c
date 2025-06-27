#include <stdlib.h>
#include <stdio.h>

int	range(int start, int end)
{
	int	size = 0;

	if (start <= end) //depende se numeros recebidos sao positivos ou negativos
		size = end - start + 1;
	else
		size = start - end + 1;
	return (size);
}

int	*ft_range(int start, int end)
{
	int i = 0;
	int size = range(start, end);
	int *dest;

	dest = malloc (sizeof(int) * size); //array de inteiros nao tem nulo no fim
	if (!dest)
		return (NULL);
	if (start <= end) //numeros positivos
	{
		while (start <= end)
		{
			dest[i] = start;
			start++;
			i++;
		}
	}
	else //numeros negativos
	{
		while (start >= end)
		{
			dest[i] = start;
			start--;
			i++;
		}
	}
	return (dest);
}

int	main(void)
{
	int	*test;
	int	size;
	int	i;

	test = ft_range(0, -3);
	size = range(0, -3);
	printf("size: %d\n", size);
	i = 0;
	while (i < size)
	{
		printf(" %d\n", test[i]);
		i++;
	}
}