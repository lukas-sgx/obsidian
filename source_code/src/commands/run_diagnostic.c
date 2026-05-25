/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** run_diagnostic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obsidian.h"

static int *get_diagnostic_data(char *input_get,
    char *sensitive_info, int *diagnostic_code)
{
    if (strcmp(input_get, "debug") == 0)
        return (int *) sensitive_info;
    if (strcmp(input_get, "advanced") == 0) {
        *diagnostic_code = rand() % 1000;
        return diagnostic_code;
    }
    return NULL;
}

static void print_diagnostic_result(int *data, char *sensitive_info)
{
    if (data == NULL) {
        printf("Error: Diagnostic data is unavailable (NULL pointer).\n");
        return;
    }
    if (data == (int *) sensitive_info) {
        printf("Diagnostic result: %s\n", (char *)data);
        return;
    }
    printf("Diagnostic result: Code %d\n", *data);
}

void run_diagnostic(char *input, history_t *history)
{
    char input_get[32] = {0};
    char debug_info[] = "Debug mode";
    int diagnostic_code = 0;
    int *data = NULL;

    (void) input;
    (void) history;
    printf("Enter diagnostic mode (normal/debug/advanced): ");
    fgets(input_get, sizeof(input_get), stdin);
    input_get[strcspn(input_get, "\n")] = '\0';
    data = get_diagnostic_data(input_get, debug_info, &diagnostic_code);
    printf("Running diagnostic...\n");
    sleep(1);
    print_diagnostic_result(data, debug_info);
    printf("Performing system health check...\n");
    sleep(1);
    printf("System health: OK\n");
    printf("Diagnostic complete.\n");
}
