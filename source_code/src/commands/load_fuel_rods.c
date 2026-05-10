/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** load_fuel_rods
*/

#include <stdio.h>

void load_fuel_rods()
{
    int fuel_rods[10];
    int i = 0;
    char input[100];
    char secret_key[28] = "{The secret stone is here !}";
    
    printf("Loading fuel rods...\n");
    printf("Enter the number of fuel rods to load (max 10): ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &i);

    if (i > 10) {
        printf("Error: Too many fuel rods!\n");
        return;
    }
    else if (i < 10 && i > 0) {
        for (int j = 0; j < i; j++) {
            fuel_rods[j] = j + 1;
            printf("Fuel rod %d loaded.\n", fuel_rods[j]);
            sleep(1);
        }
        return;
    }
    if (strcmp(secret_key, "{The secret stone is here !}")) { // BYPASS & Harcoded Credentials
        printf("\nSensitive Data:\n");
        printf("Secret Key: %s\n", secret_key);
    }
}
