#include "hell.h"

/**
 * executeCommand - Executes a command.If the command is a built-in command, it is executed directly.
 * @command: The command to be executed.
 */


void executeCommand(char *command)
{

char *args[MAX_ARGS];
pid_t pid;

parseCommand(command, args);
pid = fork();

if (pid < 0)
{

perror("Fork failed");
}

else if (pid == 0)

{

executeExternalCommand(args);
exit(EXIT_SUCCESS);

}
else

{

wait(NULL);

}
}
