#include "main.h"

int main(int ac __attribute__((unused)), char **av)
{
	char *buffer, *path, *token_array = NULL;
	size_t *bufferSize = NULL;
	int value;
	
	bufferSize = malloc(sizeof(size_t));
	if (bufferSize == NULL)
		return (1);

	while (*environ != NULL)
	{
		if (strncmp(*environ, "PATH=", 5) == 0)
		{
			path = *environ + 5;
		}
		environ++;
	}
	
	while (1)
	{
		printf("$ ");
		value = getline(&buffer, bufferSize, stdin);
		if (value == -1)
			printf("error");
		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(1);
		}
		while (*av != NULL)
		{
			av++;
		}

		token_array = strtok(path, ":");

		while (token_array != NULL)
			printf("%s", token_array);
	}
	return (0);
}
