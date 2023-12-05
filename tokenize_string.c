#include "main.h"

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
