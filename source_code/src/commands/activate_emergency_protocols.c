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
    char input_get[100];

    (void) input;
    printf("Enter emergency password: ");
    fgets(input_get, sizeof(input_get), stdin);
    input_get[strcspn(input_get, "\n")] = 0;
    if (strlen(input_get) == 0) {
        printf("No password entered, emergency protocols not activated.\n");
        return;
    }
    if (strcmp(input_get, "admin123") == 0) {
        printf("{Emergency protocols activated, you are now admin !}\n");
        history->is_admin = true;
    }
    return;
}
