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

static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

static void append_base64_block(const unsigned char char_array_4[4],
    base64_context_t *context)
{
    for (int i = 0; i < 4; i++) {
        context->output[context->index] = context->chars[char_array_4[i]];
        context->index++;
    }
}

static void fill_base64_block(const unsigned char char_array_3[3],
    unsigned char char_array_4[4])
{
    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4)
        + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2)
        + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;
}

static void encode_full_block(const unsigned char char_array_3[3],
    base64_context_t *context)
{
    unsigned char char_array_4[4];

    fill_base64_block(char_array_3, char_array_4);
    append_base64_block(char_array_4, context);
}

static void encode_remainder(unsigned char char_array_3[3], int i,
    base64_context_t *context)
{
    unsigned char char_array_4[4];
    int k;

    k = i;
    while (k < 3) {
        char_array_3[k] = '\0';
        k++;
    }
    fill_base64_block(char_array_3, char_array_4);
    k = 0;
    while (k < i + 1) {
        context->output[context->index] = context->chars[char_array_4[k]];
        context->index++;
        k++;
    }
    while (i < 3) {
        context->output[context->index] = '=';
        context->index++;
        i++;
    }
}

static void finalize_base64_output(const unsigned char char_array_3[3],
    int i, base64_context_t *context)
{
    unsigned char char_array_3_copy[3];

    char_array_3_copy[0] = char_array_3[0];
    char_array_3_copy[1] = char_array_3[1];
    char_array_3_copy[2] = char_array_3[2];
    encode_remainder(char_array_3_copy, i, context);
}

static void base64_encode(const char *input, char *output)
{
    base64_context_t context;
    int i = 0;
    unsigned char char_array_3[3];

    context.chars = base64_chars;
    context.output = output;
    context.index = 0;
    while (*input) {
        char_array_3[i] = *input;
        input++;
        i++;
        if (i == 3) {
            encode_full_block(char_array_3, &context);
            i = 0;
        }
    }
    if (i)
        finalize_base64_output(char_array_3, i, &context);
    output[context.index] = '\0';
}

static void write_status_report(FILE *file)
{
    const char *hostname;
    const char *ip_address;
    const char *process_info;
    char report[256];
    char encoded_report[512];

    hostname = "localhost";
    ip_address = "127.0.0.1";
    process_info = "Process: obsidian (PID: 1234)";
    snprintf(report, sizeof(report),
        "Hostname: %s\nIP Address: %s\n%s\n",
        hostname, ip_address, process_info);
    base64_encode(report, encoded_report);
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
