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

extern char **environ;

int main(int ac __attribute__((unused)), char **av);
<<<<<<< HEAD
char *_strtok(char *str, const char *delim);
void execute(char **av);
char *get_path(char *command);
=======
char *get_location(char *command);
>>>>>>> 0705873d95e4f9445c1615ce68c158d89834b9c3

#endif
