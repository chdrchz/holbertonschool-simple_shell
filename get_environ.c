#include "main.h"

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
	return(path);
}

void remove_path_env(char **environ)
{
	int i = 0;
	char **temp = NULL;
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			temp = &environ[i + 1];
			while (*temp != NULL)
			{
				*temp = *(temp + 1);
				temp++;
			}
			break;
		}
		i++;
	}
}
