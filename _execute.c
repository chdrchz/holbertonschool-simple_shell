#include "main.h"

void execute(char **av)
{
        char *command = NULL, *realCmd = NULL;

        if (av)
        {
                command = av[0];
                realCmd = get_cmd(command);
                if (execve(realCmd, av, NULL) == -1)
                {
                        perror("NICE TRY");
                }
        }
}
