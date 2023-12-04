#include "main.h"

int execute(char *pathStr, char **arrayStr)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == 0)
	{
		if (execve(pathStr, arrayStr, NULL) == -1)
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
	return (status);
}
