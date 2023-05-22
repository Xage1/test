#include "hell.h"

/**
 * main - start of main function
 * Return: 0 on success, any other value on error
 */
int main(void)
{
char input[MAX_PATH_LENGTH];
char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGS];
char *history[MAX_HISTORY];
int historyCount = 0;
char *line = NULL;
int i = 0;

while (1)
{
printf(";‑) ");
fflush(stdout);

line = custom_getline();

if (line == NULL)
{
break;
}

printf("You entered: %s\n", line);

strcpy(command, line);

args[i] = strtok(command, " ");
while (args[i] != NULL)
{
args[++i] = strtok(NULL, " ");
}

addHistory(history, &historyCount, command);

input[strcspn(input, "\n")] = '\0';

if (strcmp(command, "cd") == 0)
{
if (args[1] != NULL)
{
change_directory(args[1]);
}
else
{
const char *home = getenv("HOME");
if (home != NULL)
{
change_directory(home);
}
else
{
fprintf(stderr, "cd: no $HOME environment variable set\n");
}
}
}

else if (strcmp(command, "pwd") == 0)
{
printWorkingDirectory();
}
else if (strcmp(command, "echo") == 0)
{
echoMessage(args);
}
else if (strcmp(command, "help") == 0)
{
displayHelp();
}
else if (strcmp(command, "history") == 0)
{
displayHistory(history, historyCount);
}
else if (strcmp(command, "exit") == 0)
{
exitCommand(command);
}
else
{
executeCommand(command);
}
i = 0;
}

return (0);
}
