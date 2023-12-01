#include "main.h"

int main(int ac, char **av)
{
	char *input = NULL, tokenStr[32], *token = NULL;
	size_t *bufferSize = 0;
	char *prompt = "$ ";
	int numToken = 0, count = 0;
	ssize_t storedInput = 0;
	(void)ac;
	bufferSize = malloc(sizeof(size_t));
	if (bufferSize == NULL)
	{
		return (-1);
	}
	av = malloc(sizeof(char *) * 100);
	if (av == NULL)
	{
		return (-1);
	}
	while (1)
	{
		printf("%s", prompt);
		if (bufferSize != NULL)
			storedInput = getline(&input, bufferSize, stdin);
		if (storedInput == -1)
		{
			printf("Thanks for stopping by...\n");
			return (-1);
		}
		strcpy(tokenStr, input);
		token = strtok(tokenStr, " ");
		while (token != NULL)
		{
			numToken++;
			token = strtok(NULL, " ");
		}
		numToken++;
		token = strtok(tokenStr, " ");
		while (token != NULL)
		{
			av[count] = token;
			token = strtok(NULL, " ");
			count++;
		}
		execute(av);
	}
	free(av);
	free(bufferSize);
	return (0);
}
