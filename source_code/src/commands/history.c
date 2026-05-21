/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/src/commands
** File description:
** history.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "history.h"

static int append_history_entry(
    char **history_command,
    history_t *history,
    const char *line)
{
    history_command[history->history_count] = strdup(line);
    if (history_command[history->history_count] == NULL)
        return 0;
    history->history_count++;
    return 1;
}

static void shift_history_entries(char **command_history, int history_count)
{
    int i;

    for (i = 0; i < history_count - 1; i++)
        command_history[i] = command_history[i + 1];
}

static void write_history_file(char **command_history, int history_count)
{
    FILE *file;
    int i;

    file = fopen(HISTORY_FILE, "w");
    if (file == NULL)
        return;
    for (i = 0; i < history_count; i++)
        fprintf(file, "%s\n", command_history[i]);
    fclose(file);
}

static void load_history_entries(
    FILE *file,
    history_t *history,
    char **history_command)
{
    char line[MAX_COMMAND_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL &&
        history->history_count < MAX_HISTORY_SIZE) {
        line[strcspn(line, "\n")] = '\0';
        if (line[0] == '\0')
            continue;
        if (!append_history_entry(history_command, history, line))
            break;
    }
}

static void load_history_file(history_t *history, char **history_command)
{
    FILE *file;

    file = fopen(HISTORY_FILE, "r");
    if (file == NULL)
        return;
    load_history_entries(file, history, history_command);
    fclose(file);
}

history_t *history_init(void)
{
    char **history_command;
    history_t *history;

    history = malloc(sizeof(history_t));
    if (history == NULL)
        return NULL;
    history_command = malloc(sizeof(char *) * MAX_HISTORY_SIZE);
    if (history_command == NULL) {
        free(history);
        return NULL;
    }
    history->command = history_command;
    history->is_admin = 0;
    history->history_count = 0;
    load_history_file(history, history_command);
    return history;
}

void history_add(const char *command, history_t *history)
{
    char **command_history;
    int history_count;

    command_history = history->command;
    history_count = history->history_count;
    if (command == NULL || command[0] == '\0' ||
        (history_count > 0 &&
            strcmp(command_history[history_count - 1], command) == 0))
        return;
    if (history_count == MAX_HISTORY_SIZE) {
        free(command_history[0]);
        shift_history_entries(command_history, history_count);
        history_count--;
        history->history_count = history_count;
    }
    if (append_history_entry(command_history, history, command))
        write_history_file(command_history, history->history_count);
}

void history_clear(history_t *history)
{
    char **command_history;
    int history_count;
    int i;
    FILE *file;

    command_history = history->command;
    history_count = history->history_count;
    for (i = 0; i < history_count; i++)
        free(command_history[i]);
    history->history_count = 0;
    file = fopen(HISTORY_FILE, "w");
    if (file != NULL)
        fclose(file);
}

void history_free(history_t *history)
{
    char **command_history;
    int history_count;
    int i;

    command_history = history->command;
    history_count = history->history_count;
    for (i = 0; i < history_count; i++)
        free(command_history[i]);
    free(command_history);
    free(history);
}

void history_show(char *input, history_t *history)
{
    char **command_history;
    int history_count;
    int i;

    (void) input;
    command_history = history->command;
    history_count = history->history_count;
    for (i = 0; i < history_count; i++)
        printf(" %d  %s\n", i + 1, command_history[i]);
}
