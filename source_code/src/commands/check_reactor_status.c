/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** check_reactor_status
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "history.h"

static void print_status_checks(void)
{
    printf("Checking core temperature...\n");
    sleep(1);
    printf("Core temperature: Normal\n");
    sleep(1);
    printf("Checking coolant flow rate...\n");
    sleep(1);
    printf("Coolant flow rate: Stable\n");
    sleep(1);
    printf("Checking radiation levels...\n");
    sleep(2);
    printf("Radiation levels: Safe\n\n");
}

static void print_status_summary(const char *encrypted_message)
{
    printf("Encrypted message: %s\n\n", encrypted_message);
    printf("Reactor status: OK\n");
    printf("Reactor status check complete.\n\n");
}

void check_reactor_status(char *input, history_t *history)
{
    const char message[] = "ReactorStatusOK";
    char *encrypted_message = malloc(sizeof(char) * 66);

    (void) input;
    (void) history;
    printf("Starting reactor status check...\n");
    sleep(1);
    print_status_checks();
    printf("Encrypting critical reactor data...\n");
    compute_sha256_evp(message, &encrypted_message);
    sleep(1);
    print_status_summary(encrypted_message);
}
