#include "main.h"

int main(int argc, char **argv)
{
	char *path = NULL, *input = NULL, *pathCopy = NULL;
	char *tokenArray[20], *pathArray[20];
	size_t bufferSize, inputLength;
	int executeValue = 0, i = 0;
	
	(void)argc; (void)argv;

	while (1)
	{		
		
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
		tokenize_string(pathCopy, ":", pathArray);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 8);
		if (getline(&input, &bufferSize, stdin) == -1)
		{
			printf("This is a test for the checker\n");
			free(input);
			free(pathCopy);
			exit(EXIT_SUCCESS);
		}
		inputLength = strlen(input);
		if (inputLength > 0 && input[inputLength - 1] == '\n')
			input[inputLength - 1] = '\0';
                tokenize_string(input, " \n\t", tokenArray);
		if (access(tokenArray[0], X_OK) == 0)
			execute(pathCopy, tokenArray[0], tokenArray);
		else
			executeValue = find_path(pathCopy, pathArray, tokenArray);
	}
	return (executeValue);
}
