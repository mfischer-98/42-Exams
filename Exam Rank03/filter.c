#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 3

int main(int argc, char **argv) //recebo uma string ou caracter, que e o que eu quero trocar por * na frase
{
    if (argc != 2 || !*argv[1])
        return (1);

    char buffer[BUFFER_SIZE]; //podem alterar, guarda o que a read le temporariamente
    char *pattern = argv[1]; //string que vou procurar na frase
    size_t pattern_len = strlen(pattern); //tamanho da string
    ssize_t bytes_read; //para saber o resultado da funcao read

    while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0) //le enquanto a string existir
    {
        char *current = buffer; //guardamos o buffer na string, o que foi lido
        char *match; //pointer para o comeco de onde a palavra comeca na string que quero alterar

        while ((match = memmem(current, buffer + bytes_read - current, pattern, pattern_len))) //entra se der match
        { //enquanto encontrarem a match na string
            write(1, current, match - current); //escrever o caracter anterior a match

            size_t i = 0; //encontrou match i=0, comecamos a escrever os * até o fim da len
            while (i++ < pattern_len) //escrever *
                write(1, "*", 1);
			//buffer + bytes_read - current = comprimento que falta na string
            current = match + pattern_len; //pulamos pattern e o current comeca depois disso
        }
        if (current < buffer + bytes_read) //se nao tiver match, printamos a letra
            write(1, current, buffer + bytes_read - current);
    }
    return (bytes_read < 0); //retorna 1 em caso de erro de leitura -1
}