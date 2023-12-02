#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *input = NULL, *path = NULL;
	size_t size = 0;
	char *tokenArray[20], *pathArray[20];
	int returnValue = 0, i;

	(void)argc;
	(void)argv;
	while (1)
	{
		i = 0;
		while (env[i] != NULL)

		{
			if (strncmp(env[i], "PATH=", 5) == 0)
			{
				path = strdup((env[i] + 5));
				break;
			}
			i++;
		}
		tokenize_string(path, ":", pathArray);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 9);
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
		if (strcmp(tokenArray[0], "env") == 0)
		{
			for (i = 0 ; env[i] != NULL ; i++)
			{
				write(STDOUT_FILENO, env[i], strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(path);
			continue;
		}

		if (access(tokenArray[0], X_OK) == 0)
			create_child(path, tokenArray[0], tokenArray);
		else
			returnValue = check_path(path, pathArray, tokenArray);

	}
	return (returnValue);
}

void tokenize_string(char *str, char *delims, char **tokens)
{
	char *pathToken = strtok(str, delims);
	int i = 0;

	while (pathToken != NULL)
	{
		tokens[i] = pathToken;
		i++;
		pathToken = strtok(NULL, delims);
	}
	tokens[i] = NULL;
}

int check_path(char *stdpath, char **path_array, char **token_array)
{
	int i = 0;
	char *strCpy = NULL;
	struct stat j;

	while (path_array[i] != NULL)
	{
		strCpy = malloc(strlen(token_array[0]) + strlen(path_array[i]) + 2);
		strcpy(strCpy, path_array[i]);
		strcat(strCpy, "/");
		strcat(strCpy, token_array[0]);
		if (stat(strCpy, &j) == 0)
		{
			create_child(stdpath, strCpy, token_array);
			free(strCpy);
			return (0);
		}
		free(strCpy);
		i++;
	}
	return (127);
}

int create_child(char *stdpath, char *call_path, char **str_arr)
{
	pid_t pid;
	pid_t signal;
	int status = 0;

	free(stdpath);
	pid = fork();
	if (pid == 0)
	{
		if (execve(call_path, str_arr, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			signal = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	(void) signal;
	return (status);
}
