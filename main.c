#include "main.h"

int main(int ac __attribute__((unused)), char **av)
{
	char *buffer, *path = NULL;
	size_t *bufferSize = NULL;
	int value;

	bufferSize = malloc(sizeof(size_t));

	while (*environ != NULL)
	{
		if (strncmp(*environ, "PATH=", 5) == 0)
		{
			path = *environ + 5;
		}
		environ++;
	}
	printf("Path: %s", path);
	
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
			printf("%s\n", *av);
			av++;
		}
	}
	return (0);
}
