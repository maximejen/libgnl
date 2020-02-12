/*
** PERSONAL PROJECT, 2020
** lgnl
** File description:
** gnl
*/

#ifndef LGNL_GET_NEXT_LINE_H
# define LGNL_GET_NEXT_LINE_H

# define READ_SIZE 4096

char *get_next_line(int fd);
char *gnl_strcatdup(char *dest, char *src);

#endif //LGNL_GET_NEXT_LINE_H
