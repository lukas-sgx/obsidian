/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/src/commands
** File description:
** unlock_secret_mode.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "obsidian.h"

void unlock_secret_mode(char *input, history_t *history)
{
    (void) input;
    if (history->is_admin) {
        printf("Secret mode unlocked! Welcome, admin.\n");
    } else {
        printf("Access denied. You do not have the required privileges.\n");
    }
}
