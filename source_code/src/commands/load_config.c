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

void why_do_i_exist() {
    asm volatile (
        "pop %rdi\n"
        "ret\n"
    );
}

static char const adminPassword[] = "ThisIsTheBestPassword"; // Hardcoded Ccredentials

void check_password(char *str)
{
    if (strcmp(str, adminPassword) == 0) {
        printf("{Correct password! Welcome, admin.}\n"); // Flag
    }
}

void load_config()
{
    char array[8] = {};
    dprintf(1, "Loading configuration file from ./config.ini\n");
    int fd = open("./config.ini", O_RDONLY);

    read(fd, array, 100);
    if (0 /* TODO */) {
    } else {
        printf("failure!\n");
    }
    close(fd);
    return;
}
