#ifndef SHELL_H
#define SHELL_H

/**
 *shell.h - Header file for a simple shell program.
 *
 *This header file contains declarations for functions and symbols used
 *in a simple shell program.
 */

void execute_command(const char *command);
ssize_t read_command(char *buffer, size_t size);
extern void exit_builtin();

#endif

