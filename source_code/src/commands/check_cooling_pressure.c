/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** check_cooling_pressure
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void load_data(char *data)
{
    strcpy(data, "Pressure OK");
}

static void log_pressure_status(const char *status)
{
    printf("Cooling pressure status: %s\n", status);
}

static void simulate_sensor_reading()
{
    printf("Simulating sensor reading...\n");
    sleep(1);
    printf("Sensor reading complete.\n");
}

void check_cooling_pressure()
{
    char *data = (char *)malloc(16);
    char sensitive_info[32] = "{Sensitive Data}";

    load_data(data);
    printf("Cooling pressure check in progress...\n");
    sleep(2);
    simulate_sensor_reading();
    printf("Checking cooling pressure...\n");
    sleep(1);
    log_pressure_status(data);
    free(data);
    sleep(3);
    if (strcmp(data, "Pressure OK")) { // use after free
        printf("Sensitive Info: %s\n", sensitive_info);
    }
    char temp_buffer[32];
    snprintf(temp_buffer, sizeof(temp_buffer), "Temporary data: %d", rand() % 100);
    printf("Temporary buffer: %s\n", temp_buffer);
    simulate_sensor_reading();
    printf("Cooling pressure check complete.\n");
}
