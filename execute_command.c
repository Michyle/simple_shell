#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell.h"

void execute_command(const char *command) {
    pid_t pid;
    int status;

   
    pid = fork();

    if (pid == 0) { 
       
        char *args[2]; 
        args[0] = strdup(command); 
        args[1] = NULL; 
       
        if (execve(command, args, NULL) == -1) {
            perror("execve");
            free(args[0]); 
            _exit(EXIT_FAILURE);
        }
    } else if (pid < 0) { 
        perror("fork");
    } else {  
        do {
            
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

