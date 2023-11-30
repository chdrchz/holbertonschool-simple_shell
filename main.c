#include "main.h"

int main(int ac, char **av)
{
	char *input = NULL, *tokenStr = NULL, *token = NULL;
	size_t *bufferSize = 0;
	char *prompt = "$ ";
	int numToken = 0, count = 0;
	ssize_t storedInput = 0;
	av = NULL;
	(void)ac;
	tokenStr = malloc(sizeof(char) * storedInput);
	bufferSize = malloc(sizeof(size_t));
	av = malloc(sizeof(char *) * numToken);
	if (bufferSize == NULL)
	{
		free(bufferSize);
		return (-1);
	}
	if (tokenStr == NULL)
	{
		return (-1);
	}
	while (1)
	{
		printf("%s", prompt);
		storedInput = getline(&input, bufferSize, stdin);
		if (storedInput == -1)
		{
			printf("Thanks for stopping by...\n");
			return (-1);
		}
		strcpy(tokenStr, input);
		token = strtok(tokenStr, " ");
		while (token != NULL)
		{
			numToken++;
			token = strtok(NULL, " ");
		}
		numToken++;
		token = strtok(tokenStr, " ");
		while (token != NULL)
		{
			count++;
			av[count] = malloc(sizeof(char) * strlen(token));
			strcpy(av[count], token);
			token = strtok(NULL, " ");
		}
		av[count] = NULL;
		execute(av);
	}
	free(tokenStr);
	free(bufferSize);
	return (0);
}

void execute(char **av)
{
	char *command = NULL, *realCmd = NULL;

	if (av)
	{
		command = av[0];
		realCmd = get_cmd(command);
		if (execve(realCmd, av, NULL) == -1)
		{
			perror("NICE TRY");
		}
	}
}

char *get_cmd(char *command)
{
	char *path, *pathCopy, *token, *filePath;
	int cmdLen = 0, dirLen = 0;
	struct stat Buffer;

	if (strcmp(*environ, "PATH=") == 0)
		path = strdup(*environ + 5);
	if (path)
	{
		pathCopy = strdup(path);
		cmdLen = strlen(command);
		token = strtok(pathCopy, ":");
		while (token != NULL)
		{
			dirLen = strlen(token);
			filePath = malloc(cmdLen + dirLen + 2);
			strcpy(filePath, token);
			strcat(filePath, "/");
			strcat(filePath, command);
			strcat(filePath, "\0");
			if (stat(filePath, &Buffer) == 0)
			{
				free(pathCopy);
				return (filePath);
			}
			else
			{
				free(filePath);
				token = strtok(NULL, ":");
			}
		}
		free(pathCopy);
		free(path);
		if (stat(command, &Buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
