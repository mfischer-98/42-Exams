#include <unistd.h>
//falta ajeitar

int main(int argc, char **argv)
{
	int i = 0; 
	int start = 0; //inicio palavra
	//int j = 0;

	if (argc == 2)
	{
		while (argv[1][i] == ' ')
		{
			i++;
			start = i;
		}
		while (argv[1][i] != ' ')
			i++;
		while (argv[1][i] == ' ')
			i++;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		if (argv[1][i] == '\0')
			write(1, " ", 1);
		while(argv[1][start] != ' ')
		{
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
}