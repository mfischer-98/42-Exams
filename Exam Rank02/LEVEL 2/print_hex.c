#include <unistd.h>

int	ft_atoi(char *n)
{
	int	res = 0;

	while (*n >= '0' && *n <= '9')
	{
		res = res * 10 + (*n - '0');
		n++;
	}
	return (res);
}

void *print_hex(int n)
{
	char base[] = "0123456789abcdef";
	char hex;

	if (n >= 16)
		print_hex(n / 16);
	n = base[n % 16];
	write(1, &n, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);	
}