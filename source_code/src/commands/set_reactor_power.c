/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** set_reactor_power
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "obsidian.h"

static void print_overflow_warning(void)
{
    printf("\nReactor power adjustment may be incorrect.\n");
    printf("Reactor systems are behaving erratically!\n");
    printf("Reactor core temperature rising uncontrollably...\n");
    printf("{12EXPLOSION34}\n");
    printf("Emergency shutdown initiated!\n\n");
    exit(1);
}

static void print_power_result(int new_power)
{
    if (new_power < 0) {
        printf("Reactor power set to an invalid value: %d\n", new_power);
        printf("Reactor core meltdown imminent!\n");
        return;
    }
    printf("Reactor power set to: %d\n", new_power);
    printf("Reactor operating within safe parameters.\n");
}

void set_reactor_power(char *input, history_t *history)
{
    char power[11] = {0};
    int input_power = 0;
    int new_power = 0;

    (void)input;
    (void)history;
    printf("Enter reactor power level: ");
    fgets(power, sizeof(power), stdin);
    power[strcspn(power, "\n")] = 0;
    input_power = atoi(power);
    if (input_power > INT_MAX - 1000)
        print_overflow_warning();
    new_power = input_power + 1000;
    print_power_result(new_power);
}
