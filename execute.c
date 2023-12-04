#include "main.h"

void execute(char *commandPath, char *args[])
{
	pid_t pid;
	int status = 0, i = 0;
	
	printf("commandPath: %s\n", commandPath);
	while (args[i] != NULL)
	{
		printf("args[]: %s\n", args[i]);
		i++;
	}
	pid = fork();

	if (pid == 0)
	{
		if (execve(commandPath, args, environ) == -1)
		{
			printf("execve failure\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
