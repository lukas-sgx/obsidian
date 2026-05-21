/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** configure_cooling_system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obsidian.h"

static int read_configuration_file(const char *config_file,
    char *buffer, size_t size)
{
    FILE *file;

    file = fopen(config_file, "r");
    if (file == NULL)
        return 0;
    fread(buffer, 1, size - 1, file);
    buffer[size - 1] = '\0';
    fclose(file);
    return 1;
}

static void report_configuration_result(int result)
{
    if (result == 0)
        printf("Configuration applied successfully.\n");
    else
        printf("Failed to apply configuration. Command returned: %d\n", result);
}

void configure_cooling_system(char *input, history_t *history)
{
    char *config_file = "Data/cooling_config.txt";
    char buffer[64];
    int result;

    (void) input;
    (void) history;
    if (!read_configuration_file(config_file, buffer, sizeof(buffer))) {
        printf("Error: Unable to open configuration file: %s\n", config_file);
        return;
    }
    printf("Reading configuration file: %s\n", config_file);
    printf("Applying configuration: %s\n", buffer);
    result = system(buffer);
    report_configuration_result(result);
}
