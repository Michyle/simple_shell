#include "shell.h"

/**
 * child_process - A function that creates a sub process.
 * @cmmd: The pointer to tokenized command
 * @nm: The pointer to the name of shell.
 * @env: The pointer to the enviromental variables.
 * @nec: Number of execd cicles.
 * Return: Nothing.
 */
void child_process(char **cmmd, char *nm, char **env, int nec)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		exit_free(cmmd);
	}
	else if (pid == 0)
	{
		_exec(cmmd, nm, env, nec);
		_pd(cmmd);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			exit_free(cmmd);
		}
		_pd(cmmd);
	}
}


/**
  * ch_pwd - Afunction that changes working directory.
  * @path: The new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int ch_pwd(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}

