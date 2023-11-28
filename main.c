#include "main.h"

char *_strtok(char *str, const char *delim __attribute__((unused)))
{
	char *token = strtok(str, " ");
	delim = "";
	
	while (token != NULL)
	{
		strtok(NULL, " ");
		token++;
	}
	return (token);
}

int main(int ac __attribute__((unused)), char **av)
{
	char *buffer = NULL;
	char *cmdBuffer = NULL;
	size_t *bufferSize = 0;
	
	cmdBuffer = malloc(1024 * sizeof(char));
	bufferSize = malloc(sizeof(size_t));

	if (bufferSize == NULL)
		free(bufferSize);

	while (1)
	{
		printf("$ ");
		getline(&buffer, bufferSize, stdin);
		sprintf(cmdBuffer, "which %s", buffer);
		system(cmdBuffer);
		while (*av != NULL)
		{
			printf("%s\n", *av);
			av++;
		}
	}
	return (0);
}
