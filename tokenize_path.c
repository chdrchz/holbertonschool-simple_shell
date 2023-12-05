#include "main.h"

void tokenize_path(char *path, char *pathArray[], int *pathCount)
{
	char *token = strtok(path, ":");
	*pathCount = 0;

	while (token != NULL)
	{
		pathArray[*pathCount] = strdup(token);
		token = strtok(NULL, ":");
		(*pathCount)++;
	}
}
