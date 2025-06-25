/* #include <stdio.h>
 */
int	max(int* tab, unsigned int len)
{
	int	i;
	unsigned int	count;
	int	res;

	i = 0;
	count = 0;
	res = 0;
	if (!tab || len <= 0)
		return (0);
	while (count < len)
	{
		if (tab[i] > res)
			res = tab[i];
		i++;
		count++;
	}
	return (res);
}

/* int main()
{
	int int_tab[] = {1, 3, 2, 10, 9};
	printf("%d", max(int_tab, 5));
} */