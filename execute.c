#include "main.h"

int execute(char *path, char *getPath, char **strArray)
{
	pid_t pid, signal;
	int status = 0;

	free(path);
	pid = fork();

	if (pid == 0)
	{
		if (execve(getPath, strArray, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		do {
			signal = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	(void)signal;
	return (status);
}
