#include "main.h"

char *get_cmd(char *command)
{
        char *path = NULL, *pathCopy = NULL, *token = NULL, *filePath = NULL;
        int cmdLen, dirLen;
        struct stat Buffer;
        command = "";

        if (command == NULL)
                return (NULL);

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
                        filePath = malloc(cmdLen + dirLen + 2);
                        strcpy(filePath, token);
                        strcat(filePath, "/");
                        strcat(filePath, command);
                        strcat(filePath, "\0");
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
