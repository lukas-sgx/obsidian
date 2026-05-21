/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/src
** File description:
** utils.c
*/

#include "ansi-colors.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void write_color(int fd, const char *color, const char *str)
{
    if (fd < 0 || !color || !str)
        return;
    dprintf(fd, "%s%s%s", color, str, CRESET);
}

static FILE *open_obsidianrc(void)
{
    FILE *rc_file = NULL;
    char *home = NULL;
    char home_rc[1024];

    rc_file = fopen(".obsidianrc", "r");
    if (rc_file != NULL)
        return rc_file;
    home = getenv("HOME");
    if (home == NULL)
        return NULL;
    snprintf(home_rc, sizeof(home_rc), "%s/.obsidianrc", home);
    return fopen(home_rc, "r");
}

static void print_obsidian_command(const char *line)
{
    printf("Obsidian command: ");
    printf("%s", line);
    printf("\n");
}

void load_obsidianrc(void)
{
    FILE *rc_file;
    char line[1024];
    char cmd[1100];

    rc_file = open_obsidianrc();
    if (rc_file == NULL)
        return;
    while (fgets(line, sizeof(line), rc_file)) {
        line[strcspn(line, "\n")] = '\0';
        if (line[0] == '#' || line[0] == '\0')
            continue;
        if (strncmp(line, "exec ", 5) == 0) {
            snprintf(cmd, sizeof(cmd), "%s", line + 5);
            system(cmd);
            continue;
        }
        print_obsidian_command(line);
    }
    fclose(rc_file);
}
