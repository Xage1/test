#include "hell.h"

/**
 * echoMessage - Prints the message specified in the arguments
 * @args: An array containing the command arguments.
 */

void echoMessage(char **args)
{

int i = 1;
while (args[i] != NULL)
{

printf("%s ", args[i]);
i++;

}

printf("\n");
}
