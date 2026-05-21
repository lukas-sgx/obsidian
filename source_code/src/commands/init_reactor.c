/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** init_reactor
*/

#include <stdio.h>
#include <unistd.h>
#include "history.h"

void init_reactor(char *input, history_t *history)
{
    (void) input;
    (void) history;
    printf("Start of the reactor initialized\n");
    sleep(1);
    printf("Reactor status: OK\n");
    sleep(2);
    printf("Reactor core temperature: 25°C\n");
    sleep(3);
    printf("Reactor coolant flow rate: 100L/min\n");
    sleep(2);
    printf("Reactor radiation levels: Safe\n");
    sleep(3);
    printf("Reactor power output: 50MW\n");
    sleep(1);
    printf("Reactor diagnostic: All systems operational\n");
    sleep(2);
    printf("Reactor initialization complete.\n");
}
