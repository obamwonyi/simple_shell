#include "shell.h"

/**
 * execute_command - handles the command execution
 * @command: string or char that respresent the command to be executed
 * Return: None
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
		execute_child(command);
	else if (pid < 0)
		perror("Fork failed");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

