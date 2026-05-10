/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** run_diagnostic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_diagnostic()
{
    int *data = NULL;
    char input[32];
    char sensitive_info[64] = "{SECRET DIAGNOSTIC KEY}"; // Flag
    int diagnostic_code = 0;

    printf("Enter diagnostic mode (normal/debug/advanced): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "debug") == 0) {
        data = (int *)sensitive_info;
    } else if (strcmp(input, "advanced") == 0) {
        diagnostic_code = rand() % 1000;
        data = &diagnostic_code;
    }

    printf("Running diagnostic...\n");
    sleep(1);

    if (data == NULL) {
        printf("Error: Diagnostic data is unavailable (NULL pointer).\n");
    } else if (data == (int *)sensitive_info) {
        printf("Diagnostic result: %s\n", (char *)data); // Information Disclosure
    } else {
        printf("Diagnostic result: Code %d\n", *data);
    }

    printf("Performing system health check...\n");
    sleep(1);
    printf("System health: OK\n");

    printf("Diagnostic complete.\n");
}
