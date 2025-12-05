#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f) //tirar espacos
{
    char c = fgetc(f); //leio caracter
    if (c == EOF)
        return (-1);
    while (isspace(c)) //enquanto for espaco quero passar a frente
        c = fgetc(f); //iterando para frente
    ungetc(c, f); //volto 1 p tras (vou avancar um a mais no ciclo)
    return (0);
}

int match_char(FILE *f, char c) //ver se o caracter lido é o mesmo que tenho
{
    //se temos caracteres sem % antes na scanf, queremos que o user digite exatamente o que temos ali
    char    k;

    k = fgetc(f);
    if (k == c) //user digitou corretamente
        return (1);
    if (k != EOF)
        ungetc(k, f); //caso nao seja match tenho de voltar atras
    return (0);
}

int scan_char(FILE *f, va_list ap) //quando %c
{
    char    *var = va_arg(ap, char *); //procuro o nome da variável
    char    c = fgetc(f); //pego o caracter que a pessoa digitou

    if (c != EOF)
    {
        *var = c; //coloco o caracter no lugar onde a variavel está
        return (1);
    }    
    return (0);
}

int scan_int(FILE *f, va_list ap) //quando %d preciso converter para int
{
    int    *var = va_arg(ap, int *);
    int     c;
    int     sign = 1;
    int     counter = 0;
    int     num = 0;

    if (match_space(f) == -1) //pulo espacos
        return (0);
    c = fgetc(f); //leio 1o caracter
    if (c == EOF) //se comeca em EOF nao tem o que ler
        return (0);
    if (c == '+' || c == '-') //leio e pulo o sinal
    {
        if (c == '-')
            sign *= -1;
        c = fgetc(f);
     }
    while (c != EOF && (c >= '0' && c <= '9')) //leio cada numero
    {
        num = num * 10 + (c - '0'); //conversao para int
        counter++; //numero de digitos lidos
        c = fgetc(f); //next numero
    }
    if (c != EOF) //se nao for EOF tenho que voltar um
        ungetc(c, f);
    if (counter == 0) //se li 0 retorno 0
        return (0);
    *var = num * sign; //passo o numero para onde a var esta e coloco o sinal correto
    return (1);
}

int scan_string(FILE *f, va_list ap) //quando %s, ler string até o espaco e colocar \0 no fim
{
    char    *var = va_arg(ap, char *);
    char    c; //leitura de cada caracter do user
    int     i = 0;

    if (match_space(f) == -1) //pulo espacos
        return (0);
    c = fgetc(f); //leio 1o caracter
    if (c == EOF) //se comeca em EOF nao tem o que ler
        return (0);
    while (c != EOF && !isspace(c))
    {
        var[i] = (char)c;
        i++;
        c = fgetc(f);
    }
    if (c != EOF)
        ungetc(c, f);
    var[i] = '\0';
    return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap) //ver se o specifier é correto
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap); //procuramos char na lista ap?
		case 'd':
			match_space(f); //tiro os espacos
			return scan_int(f, ap);
		case 's':
			match_space(f); //tiro os espacos
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap) //*f é o input da pessoa no teclado
{
    //o que a pessoa digitou, os specifiers pedidos antes e o nome das variaveis onde vou colocar os valores em *f
	int nconv = 0;

	int c = fgetc(f); //ve se ja comecamos no EOF, nesse caso a pessoa nao digitou nada
	if (c == EOF)
		return EOF;
	ungetc(c, f); //dps de verificar, volto do comeco

	while (*format)
	{
		if (*format == '%') //procuro %, se for
		{
			format++;
			if (match_conv(f, &format, ap) != 1) //o caracter specifier é um dos que queremos?
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1) //tira os espacos, -1 caso seja EOF e o ficheiro acabou
				break;
		}
		else if (match_char(f, *format) != 1) //tenho que ver se o caracter é o mesmo, se nao paramos funcao
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv; //numero de caracteres que foram lidos
}


int ft_scanf(const char *format, ...)
{
	// inicializar lista va_list **ap e colocar tudo em ...
    va_list ap;

    va_start(ap, format);
    //scan string format e ver se tem % na vfscanf
	int ret = ft_vfscanf(stdin, format, ap); //ret = numero de caracteres lidos para return
	// cleanup da lista?
    va_end(ap);
	return ret; //retorna o numero de conversoes feitas com sucesso
}

#include <stdio.h>
int main()
{
    int num = 0;
    char c = 'a';
    int ret = 0;
    char str[100] = "Hello"; //tenho que alocar o espaco ou da segfault

/*     printf("Type a character:\n");
    ret = ft_scanf("%c", &c);
    printf("Caracter c: %c and return: %d\n\n", c, ret);

    printf("Type a number:\n");
    ret = ft_scanf("%d", &num);
    printf("Number: %d and return: %d\n\n", num, ret);

    printf("Type a sentence:\n");
    ret = ft_scanf("%s", &str);
    printf("Sentence: %s and return: %d\n\n", str, ret); */

    printf("Type str, int, char:\n");
    ret = ft_scanf("%s %d %c", &str, &num, &c);
    printf("Read: %s, %d, %c and return: %d\n\n", str, num, c, ret);
}