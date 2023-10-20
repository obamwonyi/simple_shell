#include "shell.h"

/**
 * main - main function for entering the shell process
 * @argc: input parameters count
 * @argv: input parameters
 * @envp: holds preview environment variable
 * Return: int
 */
int main(int argc, char *argv[], char *envp[])
{
	char input[MAX_INPUT_SIZE];
	int interactive = isatty(STDIN_FILENO);

	if (argc > 1)
	{
		FILE *file = fopen(argv[1], "r");

		if (!file)
		{
			perror("Error opening file");
			return (EXIT_FAILURE);
		}
		while (fgets(input, MAX_INPUT_SIZE, file))
		{
			input[strcspn(input, "\n")] = '\0';
			execute_command(input, envp);
		}

		fclose(file);
	}
	else
	{
		while (1)
		{
			if (interactive)
				printf("($) ");

			if (!fgets(input, MAX_INPUT_SIZE, stdin))
				break;

			if (strcmp(input, "exit\n") == 0)
				break;

			input[strcspn(input, "\n")] = '\0';
			execute_command(input, envp);
		}
	}

	return (0);
}
