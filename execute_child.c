#include "shell.h"

/**
 * execute_child - responsible for handling child command
 * @command: the command passed as char / string
 * @envp: environment variable
 * @program_name: name of the program
 * Return: none
 */
void execute_child(char *command, char *envp[], char *program_name)
{
	char *args[MAX_ARG_SIZE];
	char *token = strtok(command, DELIMITER);

	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, DELIMITER);
	}

	args[i] = NULL;

	execve(args[0], args, envp);

	fprintf(stderr, "%s: %d: %s: not found\n", program_name, getpid(), args[0]);
	exit(EXIT_FAILURE);
}

