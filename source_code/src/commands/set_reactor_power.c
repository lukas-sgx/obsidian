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

void set_reactor_power()
{
    char power[11];

    printf("Enter reactor power level: ");
    fgets(power, sizeof(power), stdin);
    power[strcspn(power, "\n")] = 0;

    int input_power = atoi(power);
    int new_power;

    if (input_power > INT_MAX - 1000) { // Int Overflow
        printf("\nReactor power adjustment may be incorrect.\n");
        printf("Reactor systems are behaving erratically!\n");
        printf("Reactor core temperature rising uncontrollably...\n");
        printf("{12EXPLOSION34}\n");
        printf("Emergency shutdown initiated!\n\n");
        exit(1);
    }

    new_power = input_power + 1000;

    if (new_power < 0) {
        printf("Reactor power set to an invalid value: %d\n", new_power);
        printf("Reactor core meltdown imminent!\n");
    } else {
        printf("Reactor power set to: %d\n", new_power);
        printf("Reactor operating within safe parameters.\n");
    }
}
