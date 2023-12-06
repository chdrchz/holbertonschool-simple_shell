#include "main.h"
/**
 * *get_environ - gets the environment variable, excluding "PATH="
 *
 * @environ: environment variable, globally declared in main.h
 * Return: path, excluding "PATH="
*/
char *get_environ(char **environ)
{
	int i = 0;
	char *path = NULL;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = strdup(environ[i] + 5);
			if (path == NULL)
			{
				perror("path");
				exit(EXIT_FAILURE);
			}
			break;
		}
		i++;
	}
	return (path);
}
