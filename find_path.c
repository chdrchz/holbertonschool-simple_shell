#include "main.h"

int find_path(char *path, char **pathArray, char **tokenArray)
{
	char *cmdPath = NULL;
	int i = 0;
	struct stat j;
	
	while (pathArray[i] != NULL)
	{
		cmdPath = malloc(strlen(tokenArray[0]) + strlen(pathArray[i]) + 2);
		strcpy(cmdPath, pathArray[i]);
		strcat(cmdPath, "/");
		strcat(cmdPath, tokenArray[0]);
		if (stat(cmdPath, &j) == 0)
		{
			execute(path, cmdPath, tokenArray);
			free(cmdPath);
			return (0);
		}
		free(cmdPath);
		i++;
	}
	return (127);
}
