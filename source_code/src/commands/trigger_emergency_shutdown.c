/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** trigger_emergency_shutdown
*/

#include <stdio.h>
#include <stdlib.h>
#include "obsidian.h"

// admin via activate_emergency_protocols -> admin123
void trigger_emergency_shutdown(char *input, history_t *history)
{
    (void) input;
    if (!history->is_admin) {
        printf("You are not authorized to trigger an emergency shutdown.\n");
        return;
    }
    printf("{SHUTDOWN}");
    exit(0);
}
