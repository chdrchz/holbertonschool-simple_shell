#include "main.h"

int main(int argc, char **argv)
{
	char *path = NULL, *input = NULL, *pathCopy = NULL, *token = NULL, *commandPath = NULL;
	char *tokenArray[20], *pathArray[20];
	size_t bufferSize, length;
	int counter = 0, counter2 = 0, pathCount;
	int i = 0, j = 0, k = 0;
	
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
		length = strlen(input);
        	if (length > 0 && input[length - 1] == '\n')
            		input[length - 1] = '\0';
		token = strtok(input, " ");
                counter2 = 0;
                while (token != NULL)
                {
                        tokenArray[counter2] = strdup(token);
                        token = strtok(NULL, " ");
                        counter2++;
                }
                tokenArray[counter2] = NULL;
		tokenize_path(pathCopy, pathArray, &pathCount);
		counter = 0;
		for (k = 0; k < pathCount; k++)
		{
			commandPath = malloc(strlen(pathArray[k]) + 1 + strlen("/") + strlen(input) + 1);
			printf("pathArray: %s\n", pathArray[k]);
            		strcpy(commandPath, pathArray[k]);
            		strcat(commandPath, "/");
            		strcat(commandPath, tokenArray[0]);
			printf("commandPath: %s\n", commandPath);
			if (commandPath != NULL && access(commandPath, X_OK) == 0)
			{
   				tokenArray[0] = commandPath;
				tokenArray[1] = NULL;
				execute(commandPath, tokenArray);
   				free(commandPath);
				commandPath = NULL;
				break;
			}
            		else
			{
                		free(commandPath);
				commandPath = NULL;
			}
			counter++;
		}
		for (j = 0; j < counter2; j++)
		{
			free(pathArray[j]);
		}
		for (j = 0; j < counter; j++)
        	{
            		free(tokenArray[counter2 + j]);
        	}
	}
	free(path);
	return (0);
}
