//#include "get_next_line.h"
//read file
//find \n and stop
//extract line from buffer and store what is after \n
//add what was left from before until the next \n in buffer
//end file when reading 0 bytes
//ends with \0
//free what needs to
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	pos = 0;
	static int	have = 0;
	char		*line;
	int			i, size = 0;
	
	if (fd < 0 || BUFFER_SIZE <= 0) return (NULL);
	
	// Allocate initial line buffer
	line = malloc(BUFFER_SIZE + 1);
	if (!line) return (NULL);
	
	while (1)
	{
		// Read more if buffer empty
		if (pos >= have)
		{
			have = read(fd, buf, BUFFER_SIZE);
			if (have <= 0) break;
			pos = 0;
		}
		
		// Copy from buffer to line
		for (i = pos; i < have; i++)
		{
			if (size >= BUFFER_SIZE)  // Resize if needed
			{
				char *tmp = malloc(size + BUFFER_SIZE + 1);
				if (!tmp) return (free(line), NULL);
				for (int j = 0; j < size; j++) tmp[j] = line[j];
				free(line);
				line = tmp;
			}
			
			line[size++] = buf[i];
			if (buf[i] == '\n')
			{
				line[size] = '\0';
				pos = i + 1;
				return (line);
			}
		}
		pos = have;
	}
	
	// EOF reached
	if (size > 0)
	{
		line[size] = '\0';
		return (line);
	}
	
	free(line);
	return (NULL);
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    // Test BUFFER_SIZE = 1 (char by char)
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}