#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int ac __attribute__((unused)), char **av);
char *_strtok(char *str, const char *delim);

#endif
