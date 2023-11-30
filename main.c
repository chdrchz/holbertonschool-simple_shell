#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t size = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int counter;

	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &size, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting the shell...");
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("mem allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);
		for (counter = 0; token != NULL; counter++)
		{
			argv[counter] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[counter], token);
			token = strtok(NULL, delim);
		}
		argv[counter] = NULL;
		printf("%s\n", lineptr);
		free(lineptr);
	}
	return (0);
}	

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;


	while (*environ != NULL)
	{
		if (strncmp(*environ, "PATH=", 5) == 0)
		{
			path = *environ + 5;
                }
		environ++;
	}
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else 
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}

void execmd(char **argv)
{
	char *command = NULL;
	if (argv)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
			perror("Error:");
	}
}
