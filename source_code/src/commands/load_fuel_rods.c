/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** load_fuel_rods
*/

#include <stdio.h>
#include <string.h>
#include "obsidian.h"

static void load_rods(int rod_count)
{
    int fuel_rods[10];
    int j;

    for (j = 0; j < rod_count; j++) {
        fuel_rods[j] = j + 1;
        printf("Fuel rod %d loaded.\n", fuel_rods[j]);
        sleep(1);
    }
}

static void reveal_secret_key(void)
{
    char secret_key[28] = "{The secret stone is here !}";

    if (strcmp(secret_key, "{The secret stone is here !}")) {
        printf("\nSensitive Data:\n");
        printf("Secret Key: %s\n", secret_key);
    }
}

void load_fuel_rods(char *input, history_t *history)
{
    int i;
    char input_get[100];

    (void) input;
    (void) history;
    printf("Loading fuel rods...\n");
    printf("Enter the number of fuel rods to load (max 10): ");
    fgets(input_get, sizeof(input_get), stdin);
    sscanf(input_get, "%d", &i);
    if (i > 10) {
        printf("Error: Too many fuel rods!\n");
        return;
    }
    if (i > 0 && i < 10) {
        load_rods(i);
        return;
    }
    reveal_secret_key();
}
