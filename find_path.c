#include "main.h"
/**
 * check_path - if cannot execute (ie: /bin/ls) find path and execute
 *
 * @path: path to executable (only in prototype to pass to execute)
 * @pathArray: tokenized path
 * @tokenArray: tokenized input
 * Return: On success: 0
 * On failure: 127 - command not found
*/
int check_path(char *path, char **pathArray, char **tokenArray)
{
	int i = 0;
	char *comp_path = NULL;
	struct stat x;

	while (pathArray[i] != NULL)
	{
		comp_path = malloc(strlen(tokenArray[0]) + strlen(pathArray[i]) + 2);
		strcpy(comp_path, pathArray[i]);
		strcat(comp_path, "/");
		strcat(comp_path, tokenArray[0]);
		if (stat(comp_path, &x) == 0)
		{
			execute(path, comp_path, tokenArray);
			free(comp_path);
			return (0);
		}
		free(comp_path);
		i++;
	}
	return (127);
}
