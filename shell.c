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
	char *input = NULL;
	size_t input_size = 0;
	int interactive = isatty(STDIN_FILENO);
	char *program_name = argv[0];

	if (argc > 1)
	{
		FILE *file = fopen(argv[1], "r");

		if (!file)
		{
			perror("Error opening file");
			return (EXIT_FAILURE);
		}
		while (getline(&input, &input_size, file) != -1)
		{
			input[strcspn(input, "\n")] = '\0';
			execute_command(input, envp, program_name);
		}
		fclose(file);
	}
	else
	{
		while (1)
		{
			if (interactive)
				printf("%s$ ", program_name);
			if (getline(&input, &input_size, stdin) == -1)
				break;
			if (strcmp(input, "exit\n") == 0)
				break;
			input[strcspn(input, "\n")] = '\0';
			execute_command(input, envp, program_name);
		}
	}

	free(input);
	return (0);
}
