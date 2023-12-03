#include "main.h"

int main(int argc, char **argv)
{
	char *path = NULL, *input = NULL, *pathCopy = NULL, *token = NULL, *pathToken[20];
	size_t bufferSize;
	int counter = 0;
	int i;
	
	(void)argc; (void)argv;

	while (environ[counter] != NULL)
	{
		if (strncmp(environ[counter], "PATH=", 5) == 0)
		{
			path = strdup(environ[counter] + 5);
			break;
		}
		counter++;
	}
	while (1)
	{		
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 8);
		if (getline(&input, &bufferSize, stdin) == -1)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		pathCopy = strdup(path);
                token = strtok(pathCopy, ":");
		counter = 0;
		
		while (token != NULL)
		{
			pathToken[counter] = strdup(token);
			token = strtok(NULL, ":");
			counter++;
		}

		for (i = 0; i < counter; i++)
        	{
            		printf("%s\n", pathToken[i]);
            		free(pathToken[i]);
        	}
		free(pathCopy);
	}
	free(path);
	return (0);
}
