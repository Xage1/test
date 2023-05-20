#include <stdlib.h>
#include <string.h>
#include "hell.h"

/**
 * addHistory - Adds a command to the history.If the history is full, the oldest command is removed.
 *
 * @history: An array containing the command history.
 * @count: A pointer to the number of commands in the history.
 * @command: The command to be added to the history.
 */

void addHistory(char **history, int *count, char *command)
{
if (*count == MAX_HISTORY)
{

free(history[0]);
memmove(history, history + 1, (MAX_HISTORY - 1) * sizeof(char *));
*count = MAX_HISTORY - 1;

}

history[*count] = strdup(command);

(*count)++;

}
