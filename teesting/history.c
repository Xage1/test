#include "hell.h"


/**
 * displayHistory - Displays the command history.
 * @history: An array containing the command history.
 * @count: The number of commands in the history.
 */

void displayHistory(char **history, int count)
{
int i;
for (i = 0; i < count; i++)
{

printf("%d: %s\n", i + 1, history[i]);
}
}
