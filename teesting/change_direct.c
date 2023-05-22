#include "hell.h"

#define MAX_PATH_LENGTH 1024

/**
 * change_directory - Changes the current directory.
 * @directory: An array containing the command arguments.
 */

void change_directory(const char *directory)
{
char path[MAX_PATH_LENGTH];

if (directory == NULL || strcmp(directory, "") == 0)
{

const char *home = getenv("HOME");

if (home == NULL)
{
fprintf(stderr, "cd: no $HOME environment variable set\n");
return;
}

directory = home;
}

else if (strcmp(directory, "-") == 0)
{
const char *previous_dir = getenv("OLDPWD");
if (previous_dir == NULL)
{
fprintf(stderr, "cd: no previous directory available\n");
return;

}
directory = previous_dir;
printf("%s\n", directory);

}

if (chdir(directory) != 0)
{
fprintf(stderr, "cd: failed to change directory to %s\n", directory);
return;

}

if (getcwd(path, MAX_PATH_LENGTH) == NULL)
{
fprintf(stderr, "cd: failed to get current directory\n");
return;

}

if (setenv("PWD", path, 1) != 0)
{
fprintf(stderr, "cd: failed to update PWD environment variable\n");
return;

}

if (setenv("OLDPWD", directory, 1) != 0)
{
fprintf(stderr, "cd: failed to update OLDPWD environment variable\n");
return;
}
}
