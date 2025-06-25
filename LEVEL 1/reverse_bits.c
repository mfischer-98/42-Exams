#include <stdio.h>

//unsigned char 1 byte = 8 bits
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	res = 0;

	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1); //arrasto res pra esquerda E leio o ultimo numero do binario de octet
		octet = octet >> 1; // arrasto o octet pra direita pra conseguir ler o proximo numero
	}
	return (res);
}

int	main(void) //faco o print bits para testar
{
	unsigned char bit = 0;
	unsigned char res = reverse_bits((unsigned char)3);

	int i = 8;
	while (i--)
	{
		bit = (res >> i & 1) + 48;
		printf("%c", bit);
	}
}