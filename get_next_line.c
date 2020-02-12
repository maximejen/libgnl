/*
** PERSONAL PROJECT, 2020
** lgnl
** File description:
** gnl
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

static int gnl_should_return(const char *str)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

static int gnl_strlen(const char *str)
{
    int i = -1;

    while (str && str[++i]);
    return (i);
}

char *gnl_strcatdup(char *dest, char *src)
{
    int i = 0;
    int m = 0;
    char *str = malloc(gnl_strlen(dest) + gnl_strlen(src) + 1);

    if (!str) return (NULL);
    while (dest && dest[i]) {
        str[i] = dest[i];
        i++;
    }
    while (src && src[m])
        str[i++] = src[m++];
    str[i] = 0;
    if (dest)
        free(dest);
    return (str);
}

static char *save_and_return(char **str, int idx)
{
    char *buffer = malloc(idx + 1);
    int a = 0;

    if (buffer == NULL)
        return (NULL);
    buffer = strndup(*str, idx - 1);
    if ((*str)[idx] == '\n') idx++;
    while ((*str)[idx] != '\0')
        (*str)[a++] = (*str)[idx++];
    (*str)[a] = '\0';
    return (buffer);
}

char *get_next_line(const int fd)
{
    static char *str = NULL;
    char buf[READ_SIZE + 1] = {0};
    int i = 0;

    while (gnl_should_return(str) == -1) {
        i = read(fd, buf, READ_SIZE);
        if (i == -1 || i == 0) return (NULL);
        buf[i] = 0;
        str = gnl_strcatdup(str, buf);
        if (str == NULL) return (NULL);
    }
    return (save_and_return(&str, i));
}