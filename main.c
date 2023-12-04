#include "main.h"

int main(int argc, char **argv)
{
	char *path = NULL, *input = NULL, *pathCopy = NULL, *token = NULL;
	char *tokenPath[20], *tokenArray[20];
	size_t bufferSize;
	int counter = 0, counter2 = 0;
	int i = 0, j = 0;
	
	(void)argc; (void)argv;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = strdup(environ[i] + 5);
			pathCopy = strdup(path);
			break;
		}
		i++;
	}
	while (1)
	{		
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 8);
		if (getline(&input, &bufferSize, stdin) == -1)
		{
			free(input);
			free(pathCopy);
			exit(EXIT_SUCCESS);
		}
                token = strtok(pathCopy, ":");
		counter = 0;
		while (token != NULL)
		{
			tokenPath[counter] = strdup(token);
			token = strtok(NULL, ":");
			counter++;
		}
		token = strtok(input, " ");
		counter2 = 0;
		while (token != NULL)
		{
			tokenArray[counter2] = strdup(token);
			token = strtok(NULL, " ");
			counter2++;
		}
		printf("tokenArray: %s\n", tokenArray[0]);
		printf("tokenPath: %s\n", tokenPath[0]);
		if (access(tokenPath[0], X_OK) == 0)
		{
			printf("This is working\n");
			execute(tokenArray[0], tokenArray);
			printf("This executed\n");
		}
		else
			continue;
		for (j = 0; j < counter2; j++)
		{
			/* printf("%s", tokenArray[j]); */
			free(tokenArray[j]);
		}
		for (j = 0; j < counter; j++)
        	{
            		/* printf("%s\n", tokenPath[j]); */
            		free(tokenPath[j]);
        	}
	}
	free(path);
	return (0);
}
