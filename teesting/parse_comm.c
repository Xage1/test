#include "hell.h"

/**
 * parseCommand - Parses a command into separate arguments.
 * @command: The command to be parsed.
 * @args: An array to store the parsed arguments.
 */

void parseCommand(char *command, char **args)
{
char *token;
int argIndex = 0;

token = strtok(command, " ");

while (token != NULL)
{

args[argIndex] = token;

argIndex++;

token = strtok(NULL, " ");

}

args[argIndex] = NULL;
}
