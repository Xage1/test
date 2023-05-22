#include "hell.h"

/**
 * main - start of main function
 * Return: 0 on success, any other value on error
 */

int main(void)
{

Alias aliases[MAX_ALIASES];
int aliasCount = 0;
char input[MAX_PATH_LENGTH];
char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGS];
char *history[MAX_HISTORY];
int historyCount = 0;
char *line = NULL;
int i, j, k;
char *name;
char *value;

i = 0;
j = 0;
k = 0;
name = NULL;
value = NULL;


while (1)
{
int aliasIndex = -1;

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
if (chdir(args[1]) != 0)
{
fprintf(stderr, "cd: %s: No such file or directory\n", args[1]);
}
}
else
{
const char *home = getenv("HOME");
if (home != NULL)
{
if (chdir(home) != 0)
{
fprintf(stderr, "cd: %s: No such file or directory\n", home);
}
}
else
{
fprintf(stderr, "cd: no $HOME environment variable set\n");
}
}
}

if (strcmp(command, "alias") == 0)

{
if (args[1][0] == '\0')
{

for (j = 0; j < aliasCount; j++)
{
printAlias(&aliases[j]);
}

}
else
{

for (j = 1; args[j][0] != '\0'; j++)
{

char *equalSign = strchr(args[i], '=');

if (equalSign != NULL)

{
*equalSign = '\0';
name = args[j];
value = equalSign + 1;

for (k = 0; k < aliasCount; k++)
{

if (strcmp(aliases[k].name, name) == 0)
{
aliasIndex = k;
break;
}

}


if (aliasIndex != -1)
{

strcpy(aliases[aliasIndex].value, value);
}
else if (aliasCount < MAX_ALIASES)

{
strcpy(aliases[aliasCount].name, name);
strcpy(aliases[aliasCount].value, value);
aliasCount++;

}

else

{

fprintf(stderr, "alias: maximum number of aliases reached\n");

}

}

else

{

for (k = 0; k < aliasCount; k++)

{

if (strcmp(aliases[k].name, args[j]) == 0)
{
printAlias(&aliases[k]);
break;
}
}
}
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
pid_t pid = fork();

if (pid == -1)
{

perror("fork");
exit(EXIT_FAILURE);

}
else if (pid == 0)

{
if (execvp(args[0], args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
else

{
int status;
waitpid(pid, &status, 0);
}
}
}
free(line);
return (0);
}
}
