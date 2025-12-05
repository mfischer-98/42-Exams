#include <stdlib.h>
#include <stdio.h>

void	print_solution(int *subset, int size)
{
	int i = 0;

	while (i < size)
	{
        //printar um inteiro e \n se tiver no final da linha, se nao espaco
        printf("%d", subset[i]);
        if (i == size -1)
            printf("\n");
        else
            printf(" ");
		i++;
	}
}

void	solve(int target, int *set, int *subset, int size, int subset_size, int sum, int i)
{
	if (i == size) //cheguei ao final e posso printar a solucao, base case
	{
		if (sum == target) //se a soma for igual ao target printo esse set
			print_solution(subset, subset_size);
		return ;
	}
    //backtracking: para cada elemento do set, salto para o prox elemento no set, nao incluo no subset
	solve(target, set, subset, size, subset_size, sum, i + 1); //movo o i para o proximo elemento
	
    //incluindo o set[i]
    subset[subset_size] = set[i]; //adiono este set ao subset que vou printar
	solve(target, set, subset, size, subset_size + 1, sum + set[i], i + 1); 
    //proximo subset entao aumentos 1 no size
    //tambem, aumento este set ao sum e vou para o proximo elemento (i + 1)
    //assim a cada chamada vou somar os numeros do set aos anteriore
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);

	int target = atoi(av[1]); //total que cada linha tem que dar
	int	set_size = ac - 2; //tamanho do set de numeros
	int set[set_size]; //array original com os numeros para escolher
	int	subset[set_size]; //onde guardo os arrays que crio, comeca vazio
	int	i = 0;

	while (i < set_size) //colocando cada numero no array de inteiros
	{
		set[i] = atoi(av[i + 2]); //av i + 2?
		i++;
	}
	solve(target, set, subset, set_size, 0, 0, 0); //encontrar numeros que podem dar o target como resultado
}