#include "main.h"

char *_strtok(char *str, const char *delim)
{
        char *token = strtok(str, delim);

        while (token != NULL)
        {
                strtok(NULL, delim);
                token++;
        }
        return (token);
}
