/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/src/commands
** File description:
** check_cooling_pressure.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "obsidian.h"

static void load_data(char *data)
{
    strcpy(data, "Pressure OK");
}

static void log_pressure_status(const char *status)
{
    printf("Cooling pressure status: %s\n", status);
}

static void simulate_sensor_reading(void)
{
    printf("Simulating sensor reading...\n");
    sleep(1);
    printf("Sensor reading complete.\n");
}

static void print_temporary_buffer(void)
{
    char temp_buffer[32];

    snprintf(temp_buffer, sizeof(temp_buffer),
        "Temporary data: %d", rand() % 100);
    printf("Temporary buffer: %s\n", temp_buffer);
}

void check_cooling_pressure(char *input, history_t *history)
{
    char *data = NULL;

    (void) input;
    (void) history;
    data = (char *)malloc(16);
    if (!data)
        return;
    load_data(data);
    printf("Cooling pressure check in progress...\n");
    sleep(2);
    simulate_sensor_reading();
    printf("Checking cooling pressure...\n");
    sleep(1);
    log_pressure_status(data);
    free(data);
    sleep(3);
    print_temporary_buffer();
    simulate_sensor_reading();
    printf("Cooling pressure check complete.\n");
}
