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

extern char **environ;


char* custom_getline(void);
int exitCommand(char *command);
void executeCommand(char *command);
void parseCommand(char *command, char **args);
void changeDirectory(char **args);
void printWorkingDirectory();
void echoMessage(char **args);
void displayHelp();
void displayHistory(char **history, int count);
void addHistory(char **history, int *count, char *command);
void executeExternalCommand(char **args);



#endif