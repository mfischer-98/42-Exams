#include <stdio.h>
#include <stdlib.h>

int ft_abs(int n) //transformo tds os numeros em positivos, pq quero o valor da distancia entre queens
{
	if (n >= 0)
		return (n);
	return (-n);
}

void print_sol(int *pos, int size) //printo a solucao no stdout
{
    int i = 0;

    while (i < size)
    {
        fprintf(stdout, "%d", pos[i]);
        if (i < size - 1) //enquanto nao chego no final da linha fica um espaco
            fprintf(stdout, " ");
        else
            fprintf(stdout, "\n");
        i++;
    }
}

int	is_safe(int *pos, int col, int row) //verifica se a rainha pode ser colocada na posicao
{
    int i;

    i = 0;
    while (i < col) //percorro a board, se a pos == col ja tem rainha
    {
        if (pos[i] == row)
            return (0);
        if (ft_abs(pos[i] - row) == ft_abs(col - i)) //vejo se a diagonal ta safe
        // duas queens estao na diagonal se: dist vertical = dist diagonal
        // pos[i] - row = dist vertical 
        // col - i = dist horizontal
            return (0);
        i++;
    }
    return (1);
}

void solve(int *pos, int col, int size)
{
	if (col == size) //quer dizer que acabou e entao vou printar a solucao
		return (print_sol(pos, size));
    
    int row = 0;
    
    while (row < size)
    {
		if(is_safe(pos, col, row)) //para cada row, testo se ta safe
		{
			pos[col] = row; //se sim, coloco a rainha na coluna
			solve(pos, col + 1, size); //recursividade para todas as linhas
		}
        row++;
    }
}

int main(int ac, char **av)
{
	if (ac != 2) //so posso ter 1 arg
		return (1);
	int n = atoi(av[1]); //converter str para n
	if (n <= 0)
		return (1);
	int *pos = calloc(n, sizeof(int)); 
	if (!n)
		return (1);
	solve(pos, 0, n);
	free(pos);
}