#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int	i = 0;
	int ascii[128] = {0}; //quero guardar caracteres ali que estão nas strings
	
	while (s1[i])
	{
		if (!ascii[(int)s1[i]]) //Casting do caracter na posição i, em s1. Se for o caracter A, ele sera convertido para 65 e assim, a posicao a ser verificada no array de inteiros é a 65
        {
			ascii[(int)s1[i]] = 1; //se nao tiver na lista eu adiciono e escrevo o caracter
			write(1, &s1[i], 1);
		}
		i++;
	}
	i = 0;
	while (s2[i]) //faco o mesmo para cada string
	{
		if (!ascii[(int)s2[i]])
        {
			ascii[(int)s2[i]] = 1;
			write(1, &s2[i], 1);
		}
		i++;
	}
}


int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
}