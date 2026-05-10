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

void base64_encode(const char *input, char *output)
{
    const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int i = 0, j = 0;
    unsigned char char_array_3[3], char_array_4[4];

    while (*input) {
        char_array_3[i++] = *(input++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; i < 4; i++)
                output[j++] = base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i) {
        for (int k = i; k < 3; k++)
            char_array_3[k] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (int k = 0; k < i + 1; k++)
            output[j++] = base64_chars[char_array_4[k]];

        while (i++ < 3)
            output[j++] = '=';
    }

    output[j] = '\0';
}

void send_status_report()
{
    FILE *file = fopen("Data/status_report.txt", "w");

    if (!file) {
        printf("Error: Unable to create a file in Data/, you must create a Data folder.\n");
        return;
    }

    const char *hostname = "localhost";
    const char *ip_address = "127.0.0.1";
    const char *process_info = "Process: obsidian (PID: 1234)";
    char report[256];
    snprintf(report, sizeof(report), "Hostname: %s\nIP Address: %s\n%s\n", hostname, ip_address, process_info);

    char encoded_report[512];
    base64_encode(report, encoded_report); // Weak Encryption

    fprintf(file, "Encoded Status Report:\n%s\n", encoded_report);
    fclose(file);

    printf("Status report sent and saved to 'Data/status_report.txt'.\n");
}
