#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av, char **env);
void prompt(void);
void handle(int signals);
void end_of_file(char *buffer);
void shell_exit(char **command);

void child_process(char **command, char *name, char **env, int cicles);
int ch_pwd(const char *path);
void _exec(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_getPATH(char **env);
void msgerror(char *name, int cicles, char **command);
char **tokenizing(char *buffer, const char *s);
void _pd(char **command);
void exit_free(char **command);
int compare_strings(char *s1, char *s2);
unsigned int string_length(char *s);
char *copy_string(char *dest, char *src);
int string_to_int(char *s);
char *concatenate_strings(char *dest, char *src);



#endif /* _SHELL_H_ */
