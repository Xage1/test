#include "hell.h"

/**
 * printAlias - function to print a single alias in the desired format
 *
 */

void printAlias(const Alias *alias)
{
printf("%s='%s'\n", alias->name, alias->value);
}
