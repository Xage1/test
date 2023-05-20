#include <stdlib.h>
#include <string.h>
#include "hell.h"

/**
 * exitCommand - Executes the given command in the custom shell.If the command is "exit", it terminates the shell.
 * @command: The command to execute.
 * Return: 0 if the command is successfully executed, -1 otherwise.
 */

int exitCommand(char *command)
{

if (strcmp(command, "exit") == 0)
{

printf("Exiting the shell...\n");
exit(0);

}

printf("Unknown command: %s\n", command);
return (-1);
}
