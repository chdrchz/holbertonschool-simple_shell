#include "main.h"

void execute(char **av)
{
        char *command = NULL, *realCmd = NULL;
	pid_t pid;
	int status;

        if (av)
        {
                command = av[0];
                realCmd = get_cmd(command);
		printf("%s", command);
		pid = fork();
		if (pid == 0)
		{
			if (execve(realCmd, av, environ) == -1)
                	{
                        	perror("NICE TRY");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(&status);	
		}
		else
			perror("Error while forking");
        }
}
