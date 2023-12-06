#include "main.h"
/**
 * tokenize_string - tokenizes string, stores strings at array indeces
 *
 * @str: string to be tokenized
 * @delims: delimiter to tokenize by
 * @tokens: array to hold tokenized strings
 * Return: void
 */
void tokenize_string(char *str, char *delims, char **tokens)
{
	char *path_token = strtok(str, delims);
	int i = 0;

	while (path_token != NULL)
	{
		tokens[i] = path_token;
		i++;
		path_token = strtok(NULL, delims);
	}
	tokens[i] = NULL;
}
