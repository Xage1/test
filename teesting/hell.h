#ifndef HELL_H
#define HELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10
#define MAX_HISTORY 10
#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024
#define MAX_ALIAS_LENGTH 50
#define MAX_VALUE_LENGTH 100
#define MAX_ALIASES 50

typedef struct {
char name[MAX_ALIAS_LENGTH];
char value[MAX_VALUE_LENGTH];
} Alias;


extern char **environ;


char* custom_getline(void);
int exitCommand(char *command);
void executeCommand(char *command);
void parseCommand(char *command, char **args);
void change_directory(const char *directory);
void printWorkingDirectory();
void echoMessage(char **args);
void displayHelp();
void displayHistory(char **history, int count);
void addHistory(char **history, int *count, char *command);
void executeExternalCommand(char **args);
void printAlias(const Alias *alias);


#endif
