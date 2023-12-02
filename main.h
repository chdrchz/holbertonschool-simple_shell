#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char **argv, char **env);
void tokenize_string(char *str, char *delims, char **tokens);
int check_path(char *stdpath, char **path_array, char **token_array);
int create_child(char *stdpath, char *call_path, char **str_arr);

#endif
