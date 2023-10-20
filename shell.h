#ifndef SHELL_H

#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARG_SIZE 64

#define DELIMITER " \n\t"

int main(int argc, char *argv[], char *envp[]);

void execute_command(char *command, char *envp[]);

void execute_child(char *command, char *envp[]);

#endif
