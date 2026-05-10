/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** trigger_emergency_shutdown
*/

#include <stdio.h>
#include <stdlib.h>
#include "obsidian.h"

void trigger_emergency_shutdown() // admin via activate_emergency_protocols -> admin123
{
    if (!IS_ADMIN) {
        printf("You are not authorized to trigger an emergency shutdown.\n");
        return;
    }
    printf("{SHUTDOWN}"); // flag
    exit(0);
}
