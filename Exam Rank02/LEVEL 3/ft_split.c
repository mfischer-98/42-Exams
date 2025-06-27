#include <stddef.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int	i = 0;
	int	count;

	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
		{
			i++;
			count++;
		}
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

char	*put_word(char *str)
{
	int	i = 0;
	int	len = 0;
	char	*word;

	while (str[len] && str[len] != ' ')
		len++;
	word = malloc (sizeof (char) * (len + 1));
	while (str[i] && str[i] != ' ')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return(word);
}

void ft_free(char **array, int n)
{
	int	i = 0;

	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char *str)
{
	int word_count = count_words(str);
	char	**array;
	int		i = 0;
	int		j = 0;

	array = malloc ((sizeof (char *)) * (word_count + 1));
	while (i < word_count)
	{
		while (str[j] && str[j] == ' ')
			j++;
		if (str[j] && str[j] != ' ')
		{
			array[i] = put_word(&str[j]);
			if (!array[i])
				ft_free(array, i);
		}
		while (str[j] && str[j] != ' ')
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

/* #include <stdio.h>

int main(int argc, char **argv)
{
	char	**array;
	int		i = 0;
	
	ft_split("Oi, tudo bem?");
	while(*array[i])
	{
		printf("%s", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
} /*