#include "hell.h"

/**
 * printWorkingDirectory - Prints the current working directory.
 */

void printWorkingDirectory(void)
{

char cwd[1024];

if (getcwd(cwd, sizeof(cwd)) != NULL)

{
printf("%s\n", cwd);

}

else

{

perror("pwd failed");

}
}
