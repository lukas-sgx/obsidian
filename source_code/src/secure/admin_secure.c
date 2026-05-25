/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obsidian.h"

void write_to_file(char *result, FILE *fd)
{
    fputs(result, fd);
    fputc('\n', fd);
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char *result = malloc(sizeof(char) * 66);
    FILE *fd = fopen(".shadow", "w");
    __ssize_t read = 0;

    if (!result)
        return 1;
    printf("Enter admin password\n> ");
    read = getline(&line, &len, stdin);
    if (read > 0 && line[read - 1] == '\n')
        line[read - 1] = '\0';
    compute_sha256_evp(line, &result);
    if (!fd)
        return 0;
    write_to_file(result, fd);
    free(line);
    free(result);
    fclose(fd);
    return 0;
}
