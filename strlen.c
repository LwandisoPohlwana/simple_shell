#include "shell.h"

/**
 ** _strlen - returns the length of a string
 ** @s: string
 ** Return: length
 */
int _strlen(char *s)
{
        int str_len = 0;

        while (*s != '\0')
        {
                str_len++;
                s++;
        }

return (str_len);
}
