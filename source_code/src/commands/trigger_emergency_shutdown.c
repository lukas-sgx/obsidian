/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** trigger_emergency_shutdown
*/

#include <stdio.h>
#include <stdlib.h>
#include "obsidian.h"

void trigger_emergency_shutdown(char *input, history_t *history)
{
    (void) input;
    if (!history->is_admin) {
        printf("You are not authorized to trigger an emergency shutdown.\n");
        return;
    }
    exit(0);
}
