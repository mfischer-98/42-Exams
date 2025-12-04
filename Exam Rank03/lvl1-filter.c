// Assignment name: filter
// Expected files: filter.c
// Allowed functions: read, write, strlen, memmem, memmove, malloc, calloc,
// realloc, free, printf, fprintf, stdout, stderr, perror
// --------------------------------------------------------------------------------

// Write a program that will take one and only one argument.

// Your program will then read from stdin and write all the content read in stdout
// except that every occurrence of s must be replaced by '*' (as many as the length
// of s). Your program will be tested with random buffer sizes, using a custom read
// function. Therefore the buffer being set in your program will be filled with a
// different number of chars each new call.


// For example:

// ./filter bonjour
// will behave in the same way as:
// sed 's/bonjour/*******/g'

// ./filter abc
// will behave in the same way as:
// sed's/abc/***/g'

// More generally your program must be the equivalent of the shell script filter.sh
// present in this directory (you can compare your program with it).

// In case of error during a read or a malloc, you must write "Error: " followed by
// the error message in stderr and return 1.

// If the program is called without arguments or with an empty argument or with multiple
// arguments, it must return 1.

// For example this should work:

// $> echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e
// ***defaaa***de******d***$
// $> echo 'ababcabababc' | ./filter ababc | cat -e
// *****ab*****$
// $>

// NOTES:
// memmem includes:
//                 #define _GNU_SOURCE
// 			    #include <string.h>

// perror includes:
//                 #include <errno.h>

// read includes:
//                 #include <unistd.h>


#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUF_SIZE
# define BUF_SIZE 3
#endif

void *ft_memmem(const void *haystack, size_t haystack_len,
                const void *needle, size_t needle_len)
{
    const char *h = haystack;
    const char *n = needle;
    size_t i;
    
    if (needle_len == 0)
        return (void *)haystack;
    if (haystack_len < needle_len)
        return NULL;
    
    for (i = 0; i <= haystack_len - needle_len; i++)
    {
        if (h[i] == n[0])
        {
            if (memcmp(h + i, n, needle_len) == 0)
                return (void *)(h + i);
        }
    }
    return NULL;
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1][0]) //parsing: tem que ser 2 args e nao pode ser ""
		return (1);

	char	buffer[999999];
	size_t	bytes_read;
	size_t	total = 0;
	size_t	pat_len = strlen(av[1]);
	char	*p; //pointer que vou movendo conforme leio

	while((bytes_read = read(0, buffer + total, BUF_SIZE)) > 0) //leio a frase até retornar 0
		total += bytes_read; //adiciona os bytes lidos ao total
	if (bytes_read < 0)
		return(perror("Error"), 1);
	p = buffer; //pointer = começo do buffer

	//while loop:
	//memmem(string, size, pattern, pat size)
	//p = onde começo a procurar = vai indo pra frente a cada loop
	//total - (p - buffer) = o que falta ler atualizado
	//!= NULL = enquanto tiver match na memmem continuo
	while((p = ft_memmem(p, total - (p - buffer), av[1], pat_len)) != NULL)
	{
		int i = -1;
		while(++i < pat_len) //escrever ***
			p[i] = '*';
		p += pat_len; //atualizar pointer
	}
	//escrevo o buffer inteiro modificado de uma vez só!!
	write(1, buffer, total);
	return (0);
}
