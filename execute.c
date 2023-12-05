#include "main.h"

void execute(char *commandPath, char *args[])
{
	pid_t pid;
	int status = 0;
	pid = fork();

	if (pid == 0)
	{
		if (execve(commandPath, args, environ) == -1)
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
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
