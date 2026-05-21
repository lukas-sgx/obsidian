/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** exit
*/

#include <stdlib.h>
#include <stdio.h>
#include "obsidian.h"

void quit(char *input, history_t *history)
{
    (void) input;
    (void) history;
    printf("Exiting program...\n");
    exit(0);
}
