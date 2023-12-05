#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

extern char **environ;

int main(int argc, char **argv);
int execute(char *path, char *getPath, char **strArray);
void tokenize_string(char *str, char *delims, char **tokens);
int find_path(char *path, char **pathArray, char **tokenArray);

#endif
