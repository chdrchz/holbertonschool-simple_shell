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
#include <stddef.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char **argv);
void tokenize_string(char *str, char *delims, char **tokens);
int execute(char *stdpath, char *call_path, char **str_arr);
int check_path(char *path, char **pathArray, char **tokenArray);
char *get_environ(char **environ);
void remove_path_env(char **environ);
/* void one_exit(char *input, char *path); */
void two_exit(char *input, char *path, int exitStatus); 

#endif
