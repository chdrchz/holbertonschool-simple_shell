#include "main.h"

int main(int argc, char **argv)
{
	char *input = NULL, *path = NULL, *tokenArray[20], *pathArray[20];
	size_t size = 0;
	int returnValue = 0;
	(void)argc; (void)argv;
	while (1)
	{
		path = get_environ(environ);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 8);
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		tokenize_string(path, ":", pathArray);
		tokenize_string(input, " \n\t", tokenArray);
		if (!tokenArray[0])
		{
			free(path);
			continue;
		}
		if (strcmp(tokenArray[0], "exit") == 0)
			handle_exit(input, path);
		if (access(tokenArray[0], X_OK) == 0)
			execute(path, tokenArray[0], tokenArray);
		else
			returnValue = check_path(path, pathArray, tokenArray);
	}
	return (returnValue);
}

void handle_exit(char *input, char *path)
{
	free(input);
	free(path);
	exit(EXIT_SUCCESS);
}
