#include "main.h"

int check_path(char *path, char **pathArray, char **tokenArray);

int main(int argc, char **argv)
{
	char *input = NULL, *path = NULL;
	size_t size = 0;
	char *tokenArray[20], *pathArray[20];
	int ret_value = 0, i;

	(void)argc;
	(void)argv;
	while (1)
	{
		i = 0;
		while (environ[i] != NULL)

		{
			if (strncmp(environ[i], "PATH=", 5) == 0)
			{
				path = strdup((environ[i] + 5));
				break;
			}
			i++;
		}
		tokenize_string(path, ":", pathArray);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 8);
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		tokenize_string(input, " \n\t", tokenArray);

		if (!tokenArray[0])
		{
			free(path);
			continue;
		}
		if (strcmp(tokenArray[0], "exit") == 0)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		/* if (strcmp(tokenArray[0], "env") == 0)
		{
			for (i = 0 ; env[i] != NULL ; i++)
			{
				write(STDOUT_FILENO, env[i], _strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(path);
			continue;
		} */

		if (access(tokenArray[0], X_OK) == 0)
			execute(path, tokenArray[0], tokenArray);
		else
			ret_value = check_path(path, pathArray, tokenArray);

	}
	return (ret_value);
}
