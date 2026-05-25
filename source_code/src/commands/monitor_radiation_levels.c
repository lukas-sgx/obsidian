/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** monitor_radiation_levels
*/

#include <stdio.h>
#include <string.h>
#include "obsidian.h"

void monitor_radiation_levels(char *input, history_t *history)
{
    char buffer[10] = {0};

    (void) input;
    (void) history;
    printf("Enter radiation levels: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Radiation Levels: %s\n", buffer);
}
