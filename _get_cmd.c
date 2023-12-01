#include "main.h"

char *get_cmd(char *command)
{
        char *path = NULL, *pathCopy = NULL, *token = NULL, *filePath = NULL;
        int cmdLen, dirLen;
        struct stat Buffer;

        if (command == NULL)
	{
                return (NULL);
		exit(1);
	}

        while (*environ != NULL)
        {
                if (strncmp(*environ, "PATH=", 5) == 0)
                {
                        path = strdup(*environ + 5);
                        break;
                }
                environ++;
        }
        if (path)
        {
                pathCopy = strdup(path);
                cmdLen = strlen(command);
                token = strtok(pathCopy, ":");
                while (token != NULL)
                {
                        dirLen = strlen(token);
                        filePath = malloc(cmdLen + dirLen + 1);
                        strcpy(filePath, token);
                        strcat(filePath, "/");
                        strcat(filePath, command);
                        if (stat(filePath, &Buffer) == 0)
                        {
				free(pathCopy);
                                return (filePath);
                        }
                        else
                        {
				free(filePath);
                                token = strtok(NULL, ":");
                        }
                }
                free(pathCopy);
                free(path);
                if (stat(command, &Buffer) == 0)
                        return (command);
                return (NULL);
        }
        return (NULL);
}
