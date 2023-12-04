#include "main.h"

int main(int argc, char **argv)
{
	char *path = NULL, *input = NULL, *pathCopy = NULL, *token = NULL;
	char *tokenPath[20], *tokenArray[20], *concatArray[20];
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
			printf("\n");
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
			/* printf("Input: %s\n", tokenArray[counter2]); */
			counter2++;
		}
		concatArray[0] = malloc(strlen(tokenPath[0]) + 1 + strlen("/") + strlen(tokenArray[0]) + 1);
		strcpy(concatArray[0], tokenPath[0]);
		strcat(concatArray[0], "/");
		strcat(concatArray[0], tokenArray[0]);
		if (access(tokenPath[0], X_OK) == 0)
		{
			/* printf("This is working\n"); */
			execute(concatArray, tokenArray);
			/* printf("This executed\n"); */
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
		free(concatArray[0]);
	}
	free(path);
	return (0);
}
