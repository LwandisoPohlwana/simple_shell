#include "shell.h"

/**
 * main - the main shell
 * return: 0
 */

int main()
{
        char *prompt = "$ ";
        char *input = NULL;
        char command[100];
        char *args[MAX_ARGUMENTS + 1];
        int numofargs;
        size_t input_length = 0;

        while (1)
        {
                write(STDOUT_FILENO, prompt, 2);

                if (getline(&input, &input_length, stdin) == -1)
                        break;

                numofargs = tokeniz(input, command, args);

                if (numofargs > 0)
                {
                if (access(command, X_OK) == 0)
                        execute_command(command, args);
                else
                        printf("Command not found: %s\n", command);
                }
        }

        free(input);
        return 0;
}
