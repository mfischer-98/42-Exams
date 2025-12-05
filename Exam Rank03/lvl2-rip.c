#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	is_valid(char *str, int *rm, int rm_size)
{
	int i = 0; //itera na string
    int j = 0; //itera no rm
	int balance = 0;

    while (str[i])
    {
        if (j < rm_size && i == rm[j]) //removo o caracter
        {
            j++;
            i++;
            continue ;
        }
        if (str[i] == '(')
            balance++;
        if (str[i] == ')')
            if (--balance < 0) //ta desequilibrado
                return (0);
        i++;
    }
	return (balance == 0); //é valido, 1
}

void print_solution(char *str, int *rm, int rm_size)
{
    int i = 0;
	int j = 0;
	while(str[i])
	{
		if (j < rm_size && i == rm[j]) //se o index ta no remove
		{
			write(1, " ", 1); //coloca o espaco se o caracter foi removido
			j++;
		}
		else
			write(1, &str[i], 1);
        i++;
	}
	write(1, "\n", 1);
}

void	solve(char *str, int str_size, int *rm, int rm_size, int start, int i)
//recebe string, strlen, array vazio rm, tam dele = remove, start 0, int 0
{
	if (i == rm_size) //base case, acabou
	{
		if (is_valid(str, rm, rm_size)) //vejo se tem balance, so imprimo estes casos
			print_solution(str, rm, rm_size);
		return ;
	}
	int j = start;
	while (j < str_size) //testo todas as posicoes e se nao for valido nao printo e passo para a próxima
	{
		rm[i] = j; //escolhe o index que vai remover
		solve(str, str_size, rm, rm_size, start + 1, i + 1); //aumento i e start
		j++; //testo proxima posicao dps da recursividade
	}
}

int main(int argc, char **argv)
{
    if (argc != 2)
    return (1);

    char    *str = argv[1];
    int i = 0;
    int balance = 0; //conta quantos () tenho e ve se tenho um a mais
    int remove = 0; //vejo se tenho que remover

    while (str[i])
    {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')')
        {
            if (balance > 0)
                balance--;
            else
                remove++;
        }
        i++;
    }
    remove += balance; //numero de parentesis a remover
    int rm[remove];
    solve(str, i, rm, remove, 0, 0);
    return (0);
}