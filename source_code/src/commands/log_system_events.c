/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** log_system_events
*/

#include <stdio.h>
#include <string.h>
#include "obsidian.h"

void log_system_event(char *input, history_t *history)
{
    FILE *log = NULL;
    char command[100] = {0};
    char input_get[100] = {0};

    (void) history;
    (void) input;
    printf("Enter command: ");
    fgets(input_get, sizeof(input_get), stdin);
    sscanf(input_get, "%99s", command);
    log = fopen("Data/system.log", "a");
    if (!log) {
        printf("Error: Unable to open log file 'Data/system.log'.\n");
        return;
    }
    printf("Logging event: %s\n", input_get);
    fprintf(log, "EVENT: %s\n", input_get);
    fclose(log);
}
