/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** activate_emergency_protocols
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "obsidian.h"

void activate_emergency_protocols(char *input, history_t *history)
{
    char *line = NULL;
    size_t len = 0;

    (void) input;
    printf("Enter emergency password: ");
    getline(&line, &len, stdin);
    line[strcspn(line, "\n")] = 0;
    if (strlen(line) == 0) {
        printf("No password entered, emergency protocols not activated.\n");
        return;
    }
    if (verify_hash(line)) {
        history->is_admin = true;
    } else {
        printf("Bad password you can't be admin or admin account isn't set\n");
    }
    if (line)
        free(line);
    return;
}
