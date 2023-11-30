#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(int ac __attribute__((unused)), char **av);
char *_strtok(char *str, const char *delim);
void execute(char **av);
char *get_path(char *command);

#endif
