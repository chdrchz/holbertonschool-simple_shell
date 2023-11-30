#include "main.h"

int main(int ac, char **av)
{
	char *input, *tokenStr, *token = NULL;
	size_t *bufferSize = 0;
	char *prompt = "$ ";
	int numToken = 0, count = 0, i = 0;
	ssize_t storedInput = 0;
	(void)ac;
	tokenStr = malloc(sizeof(char) * storedInput);
	bufferSize = malloc(sizeof(size_t));
	av = malloc(sizeof(char) * numToken);
	if (bufferSize == NULL)
	{
		free(bufferSize);
		return (-1);
	}
	if (tokenStr == NULL)
	{
		free(tokenStr);
		return (-1);
	}
	while (1)
	{
		printf("%s", prompt);
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
			count++;
			av[count] = malloc(sizeof(char) * strlen(token));
			strcpy(av[count], token);
			token = strtok(NULL, " ");
		}
		/* loop for testing purposes only */
		for (i = 0; i < numToken - 1; i++)
			printf("%s", av[count]);
		av[count] = NULL;
		free(tokenStr);
		free(bufferSize);
		free(av);
	}
  return (0);
}
