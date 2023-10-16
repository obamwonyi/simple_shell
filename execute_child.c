#include "shell.h"

/**
 * execute_child - responsible for handling child command
 * @command: the command passed as char / string
 * Return: none
 */
void execute_child(char *command)
{
	char *args[MAX_INPUT_SIZE];
	char *token = strtok(command, " \n");

	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}

	args[i] = NULL;

	execvp(args[0], args);

	perror("Error");
	exit(EXIT_FAILURE);
}

