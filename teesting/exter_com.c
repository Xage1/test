#include "hell.h"


/**
 * executeExternalCommand - Executes an external command.
 * @args: An array containing the command arguments.
 */

void executeExternalCommand(char **args)
{

if (execvp(args[0], args) == -1)
{

perror("execvp failed");

exit(EXIT_FAILURE);

}
}
