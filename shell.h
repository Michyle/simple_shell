#ifndef SHELL_H
#define SHELL_H

void execute_command(const char *command);
ssize_t read_command(char *buffer, size_t size);
extern void exit_builtin();
#endif

