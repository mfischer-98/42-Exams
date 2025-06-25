#include <stdio.h>

int	is_valid(const char c, int base_len) //preciso passar os numeros aqui e se for valido retornar 1
{
	char base_l[] = "0123456789abcdef";
	char base_u[] = "0123456789ABCDEF";
	int i = 0;

	while (i < base_len)
	{
		if (c == base_l[i] || c == base_u[i])
			return(1);
		i++;
	}
	return (0);
}
int	ft_atoi_base(const char *str, int str_base) //dou o numero em str e a base, preciso transformar em int
{
	int	res = 0;
	int	neg = 1;
 
	while ((*str == ' ') || (*str >= 9 && *str <= 13)) //pular espacos
		str++;
	if (*str == '-') //so aceita um sinal de menos
	{
		neg = -1;
		str++;
	}
	while (*str && is_valid(*str, str_base)) //se a string existir e estiver na base
	{
		res *= str_base; //resultado = a ele * o tamanho da base 0 na primeira e depois *10 ou *4
		if (*str >= '0' && *str <= '9') //se for um numero so tiro 47 e vira ele mesmo em inteiro
			res += *str - '0';
		else if ((*str >= 'a' && *str <= 'f')) //se for uma letra, tiro o a(97) e coloco + 10
			res += *str - 'a' + 10;
		else if ((*str >= 'A' && *str <= 'F'))
			res += *str - 'A' + 10;
		str++;
	}
	return (res * neg);
}

/*int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_atoi_base(argv[1], 10));
	}
} */