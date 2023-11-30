#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

extern char **environ;

int main(int ac, char **av);
char *_strtok(char *str, const char *delim);
void execute(char **av);
char *get_cmd(char *command);
char *get_location(char *command);

#endif
