#include <stdio.h>

//unsigned char 1 byte = 8 bits
unsigned char	reverse_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
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