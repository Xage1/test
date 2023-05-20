#include "hell.h"

/**
 * changeDirectory - Changes the current directory.
 * @args: An array containing the command arguments.
 */

void changeDirectory(char *args[])
{
if (args[1] == NULL)

{

fprintf(stderr, "cd: expected argument to \"cd\"\n");
}

else

{

if (chdir(args[1]) != 0)
{

perror("cd failed");
}
}
}
