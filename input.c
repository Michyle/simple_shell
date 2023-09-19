#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell.h"
#include <string.h>
ssize_t read_command(char *buffer, size_t size) {
    ssize_t bytes_read;
    bytes_read = read(STDIN_FILENO, buffer, size);
    return bytes_read;
}

