/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "obsidian.h"
#include "utils.h"

void load_config(char *input, history_t *history)
{
    char array[8] = {0};
    int fd;

    (void) input;
    (void) history;
    if (!history->is_admin)
        return;
    dprintf(1, "Loading configuration file from ./config.ini\n");
    fd = open("./config.ini", O_RDONLY);
    if (0 != read(fd, array, sizeof(array)))
        printf("failure!\n");
    close(fd);
    return;
}
