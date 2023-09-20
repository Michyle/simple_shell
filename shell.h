#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 *shell.h - Header file for a simple shell program.
 *
 *This header file contains declarations for functions and symbols used
 *in a simple shell program.
 */

void execute_command(const char *command);
ssize_t read_command(char *buffer, size_t size);
extern void exit_builtin();

#define BUFFER_SIZE 1024

#endif

