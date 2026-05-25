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
#include "obsidian.h"

static void print_status_report(int random_number, const char *reactor_status)
{
    printf("Reactor core temperature: %d\n", random_number);
    printf("Reactor core status: %s\n", reactor_status);
}

static void report_status(int random_number, const char *message,
    const char *reactor_status)
{
    printf("%s\n", message);
    print_status_report(random_number, reactor_status);
}

static void report_overheating(int random_number)
{
    printf("Meltdown simulated! Reactor core is overheating.\n");
    print_status_report(random_number, "Reactor Overheating");
}

static void handle_meltdown_status(int random_number)
{
    if (random_number < 10) {
        report_overheating(random_number);
        return;
    }
    if (random_number < 20) {
        report_status(random_number,
            "Warning: Reactor core temperature rising.",
            "Reactor Warning");
        return;
    }
    if (random_number < 50) {
        report_status(random_number,
            "Alert: Reactor core temperature stable.",
            "Reactor Stable");
        return;
    }
    report_status(random_number, "Reactor core temperature normal.",
        "Reactor Normal");
}

void simulate_meltdown(char *input, history_t *history)
{
    int random_number = rand() % 100;

    (void)input;
    (void)history;
    printf("Generated random number: %d\n", random_number);
    handle_meltdown_status(random_number);
}
