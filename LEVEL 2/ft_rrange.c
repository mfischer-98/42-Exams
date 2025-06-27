#include <stdio.h>
#include <stdlib.h>

int	ft_size(int start, int end)
{
	int	size = 0;

	if (end >= start)
		size = end - start + 1;
	else
		size = start - end + 1;
	return (size);
}

int *ft_rrange(int start, int end)
{
	int *dest;
	int i = 0;
	int size = ft_size(start, end);

	dest = malloc (sizeof(int) * size);
	if (!dest)
		return NULL;
	if (start <= end)
	{
		while (start <= end)
		{
			dest[i] = end;
			i++;
			end--;
		}
	}
	else
	{
		while (start >= end)
		{
			dest[i] = end;
			i++;
			end++;
		}
	}
	return (dest);
}