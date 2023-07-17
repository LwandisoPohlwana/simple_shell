#include "shell.h"

/**
 * execute - executes the command
 * @command: char pointer to the command
 * @args: arguments
 * Return: void
 */

void execute_command(char *command, char *args[])
{
        pid_t pid;

        pid = fork();

        if (pid < 0)
        {
                perror("fork() failed");
                exit(1);
        }
        else if (pid == 0)/*Child process*/
        {
                if (execve(command, args, NULL) == -1)
                {
                perror("execlp() failed");
                exit(1);
                }
        }
        else/*Parent process*/
        {
                int status;
                waitpid(pid, &status, 0);
        }
}
