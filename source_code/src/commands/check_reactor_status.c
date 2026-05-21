/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** check_reactor_status
*/

#include <stdio.h>
#include <unistd.h>
#include "history.h"

static char shift_char(char character, int shift)
{
    if (character >= 'A' && character <= 'Z')
        return ((character - 'A' + shift) % 26) + 'A';
    if (character >= 'a' && character <= 'z')
        return ((character - 'a' + shift) % 26) + 'a';
    return character;
}

void encrypt_message(const char *input, char *output, int shift)
{
    int i;

    for (i = 0; input[i] != '\0'; i++)
        output[i] = shift_char(input[i], shift);
    output[i] = '\0';
}

static void print_status_summary(const char *encrypted_message)
{
    printf("Encrypted message: %s\n\n", encrypted_message);
    printf("Reactor status: OK\n");
    printf("Reactor status check complete.\n\n");
}

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

void check_reactor_status(char *input, history_t *history)
{
    const char *message = "ReactorStatusOK";
    char encrypted_message[50] = {0};

    (void) input;
    (void) history;
    printf("Starting reactor status check...\n");
    sleep(1);
    print_status_checks();
    printf("Encrypting critical reactor data...\n");
    encrypt_message(message, encrypted_message, 3);
    sleep(1);
    print_status_summary(encrypted_message);
}
