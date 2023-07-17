#include "shell.h"

/**
 * tokeniz - tokenize the input
* tokeniz - tokenize the input
 * @input: the user input
 * @command: command in the inpu
 * @agrs: arguments
 * retuen ; number or args
 */

int tokeniz(char *input, char *command, char *args[])
{
        int numofargs = 0;
        char *token;

        token = strtok(input, " ");

        if (token == NULL)
                return 0;

        _strcpy(command, token);
        args[numofargs++] = token;

        while ((token = strtok(NULL, " ")) != NULL && numofargs < MAX_ARGUMENTS)
        {
                args[numofargs++] = token;
        }

        args[numofargs] = NULL;

        return numofargs;
}
