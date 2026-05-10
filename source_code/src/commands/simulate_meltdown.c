/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** simulate_meltdown
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void simulate_meltdown()
{
    char reactor_status[32] = "Reactor Stable";
    int random_number = rand() % 100; // Race condition
    char secret_code[16] = "{MELTDOWN1234}";

    printf("Generated random number: %d\n", random_number);

    if (random_number < 10) {
        printf("Meltdown simulated! Reactor core is overheating.\n");
        strcpy(reactor_status, "Reactor Overheating");

        if (random_number < 5) {
            printf("Critical Error: Secret Code Leaked: %s\n", secret_code);
            return;
        }
    } else if (random_number < 20) {
        printf("Warning: Reactor core temperature rising.\n");
        strcpy(reactor_status, "Reactor Warning");
    } else if (random_number < 50) {
        printf("Alert: Reactor core temperature stable.\n");
        strcpy(reactor_status, "Reactor Stable");
    } else {
        printf("Reactor core temperature normal.\n");
        strcpy(reactor_status, "Reactor Normal");
    }
    printf("Reactor core temperature: %d\n", random_number);
    printf("Reactor core status: %s\n", reactor_status);
}
