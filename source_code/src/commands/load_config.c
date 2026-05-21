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

static char const adminPassword[] =
    "ThisIsTheBestPassword";

void check_password(char *str)
{
    if (strcmp(str, adminPassword) == 0)
        printf("{Correct password! Welcome, admin.}\n");
}

void load_config(char *input, history_t *history)
{
    char array[8] = {};
    int fd;

    (void) input;
    (void) history;
    dprintf(1, "Loading configuration file from ./config.ini\n");
    fd = open("./config.ini", O_RDONLY);
    read(fd, array, sizeof(array));
    if (0)
        ;
    else
        printf("failure!\n");
    close(fd);
    return;
}
