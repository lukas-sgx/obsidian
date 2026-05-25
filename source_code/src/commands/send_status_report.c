/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** send_status_report
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "obsidian.h"

static void write_status_report(FILE *file)
{
    const char *hostname;
    const char *ip_address;
    const char *process_info;
    char report[256];
    char *encoded_report = malloc(sizeof(char) * 66);

    if (!encoded_report)
        return;
    hostname = "localhost";
    ip_address = "127.0.0.1";
    process_info = "Process: obsidian (PID: 1234)";
    snprintf(report, sizeof(report),
        "Hostname: %s\nIP Address: %s\n%s\n",
        hostname, ip_address, process_info);
    compute_sha256_evp(report, &encoded_report);
    fprintf(file, "Encoded Status Report:\n%s\n", encoded_report);
}

void send_status_report(char *input, history_t *history)
{
    FILE *file = fopen("Data/status_report.txt", "w");

    if (!file) {
        printf("Error: Unable to create a file in Data/. ");
        printf("You must create a Data folder.\n");
        return;
    }
    (void)input;
    (void)history;
    write_status_report(file);
    fclose(file);
    printf("Status report sent and saved to 'Data/status_report.txt'.\n");
}
