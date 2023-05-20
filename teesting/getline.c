#include <stdio.h>
#include <unistd.h>
#include "hell.h"

#define BUFFER_SIZE 1024

/**
 * custom_getline - function reads characters from the standard input using the read system call
 * Return: New character from input
 */

char *custom_getline(void)
{
static char buffer[BUFFER_SIZE];
static int buffer_pos = 0;
static int buffer_size = 0;

int newline_pos = -1;
int i;
char *line;

if (buffer_pos >= buffer_size)
{
buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
buffer_pos = 0;

if (buffer_size <= 0)
{
return (NULL);
}

}

for (i = buffer_pos; i < buffer_size; i++)
{
if (buffer[i] == '\n')
{

newline_pos = i;
break;

}
}

if (newline_pos != -1)
{
buffer[newline_pos] = '\0';
line = &buffer[buffer_pos];
buffer_pos = newline_pos + 1;
   
}

else

{
line = &buffer[buffer_pos];
buffer_pos = buffer_size;

}

return (line);
}
