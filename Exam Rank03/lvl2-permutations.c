#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

void	ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_sort(char *str, int len) //ordem alfabetica
{
	int i = 0;
	while (i < len - 1)
	{
		int j = 0;
		while (j < len - i - 1)
		{
			if (str[j] > str[j + 1])
				ft_swap(&str[j], &str[j + 1]); //faco swap se a proxima for depois no alfabeto
			j++;
		}
		i++;
	}
}

//Lexicographical Permutation Algorithm
//procuro a menor permutacao que ja ta sorted e comeco as outras permutacoes por ai
int	ft_next_permutation(char *str, int len)
{
	int i = len - 2; //pego o ultimo caracter que pode ser trocado, o penultimo
	while (i >= 0 && str[i] >= str[i + 1]) //queremos encontrar o numero mais a direita que pode ser aumentado
		i--; //i vai ser o nosso pivot
	if (i < 0)
		return 0; //quando da zero acabamos as permutacoes
	int j = len - 1; //j comeca no fim e comparamos com i para fazer as trocas
	while (str[j] <= str[i]) //ve o LSCaracter (direita) e altera este se for necessario
		j--;
	ft_swap(&str[i], &str[j]);
    //precisamos reverter o numero depois da troca, pq depois do i fica descendente
	int start = i + 1; //caracter dps do pivot
	int end = len - 1; //final da string
	while (start < end)
		ft_swap(&str[start++], &str[end--]);
	return 1;
}

int	main(int argc, char **argv)
{
	if (argc != 2) //quero 1 arg = string
		return 1;
	char *str = argv[1]; //guardo str
	int len = ft_strlen(str); //guardo len
	ft_sort(str, len); //faco sort da string
	puts(str);
	while (ft_next_permutation(str, len))
		puts(str);
	return 0;
}