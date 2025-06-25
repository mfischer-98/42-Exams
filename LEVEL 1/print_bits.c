#include <unistd.h>

//unsigned char 1 byte = 8 bits
void print_bits(unsigned char octet)
{
	int	i = 8; //because we have 8 bits
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0'; // arrasto o octet todo para a direita e leio o ultimo digito, que vai ser o primeiro a escrever
		//& 1: ler o ultimo digito que vemos (o da posicao i)
		write(1, &bit, 1);
	}
}

int	main(void)
{
	print_bits(255); // Should print: 00000010
	return (0);
}