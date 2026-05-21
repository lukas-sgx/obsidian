/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/include
** File description:
** history.h
*/

#ifndef HISTORY_H
    #define HISTORY_H

    #define MAX_COMMAND_LENGTH 256
    #define HISTORY_FILE ".obsidian_history"
    #define MAX_HISTORY_SIZE 1000

typedef struct history_s {
    char **command;
    int history_count;
    int is_admin;
} history_t;

history_t *history_init(void);
void history_add(const char *command, history_t *history);
void history_clear(history_t *history);
void history_free(history_t *history);
void history_show(char *input, history_t *history);

#endif /* HISTORY_H */
