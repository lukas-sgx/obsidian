/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/src
** File description:
** my_console.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/types.h>
#include "obsidian.h"
#include "ansi-colors.h"
#include "utils.h"
#include "history.h"

static const char *const command_strings[COMMAND_COUNT] = {
    "init_reactor",
    "check_reactor_status",
    "activate_emergency_protocols",
    "simulate_meltdown",
    "check_cooling_pressure",
    "send_status_report",
    "monitor_radiation_levels",
    "set_reactor_power",
    "run_diagnostic",
    "enable_remote_access",
    "quit",
    "help",
    "load_fuel_rods",
    "log_system_event",
    "unlock_secret_mode",
    "load_config",
    "history",
    "configure_cooling_system",
    "trigger_emergency_shutdown",
    "init_labo",
    "init_workers",
    "call_api",
    "alchemy",
};

static const char *const command_strings_lib[COMMAND_COUNT_LIB] = {
    "init_steam_turbine",
    "read_turbine_config",
    "turbine_remote_access",
    "turbine_temperature",
    "run_turbine",
};

static const command_fn_t builtin_commands[COMMAND_COUNT] = {
    init_reactor,
    check_reactor_status,
    activate_emergency_protocols,
    simulate_meltdown,
    check_cooling_pressure,
    send_status_report,
    monitor_radiation_levels,
    set_reactor_power,
    run_diagnostic,
    enable_remote_access,
    quit,
    help,
    load_fuel_rods,
    log_system_event,
    unlock_secret_mode,
    load_config,
    history_show,
    configure_cooling_system,
    trigger_emergency_shutdown,
    init_labo,
    init_workers,
    call_api,
    alchemy,
};

void check_pepito_lib(char *input)
{
    void *dlh = dlopen("obsidian_lib.so", RTLD_LAZY);
    void (*fnc)(void) = NULL;

    if (dlh == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    fnc = (void (*)(void)) dlsym(dlh, input);
    if (fnc == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    fnc();
}

static bool handle_builtin_command(char *line,
    command_fn_t f[COMMAND_COUNT], history_t *history)
{
    for (int i = 0; i < COMMAND_COUNT; i++) {
        if (strcmp(line, command_strings[i]) == 0) {
            f[i](line, history);
            return true;
        }
    }
    return false;
}

static bool handle_library_command(char *line)
{
    for (int i = 0; i < COMMAND_COUNT_LIB; i++) {
        if (strcmp(line, command_strings_lib[i]) == 0) {
            check_pepito_lib(line);
            return true;
        }
    }
    return false;
}

static bool resolve_history_command(const char **line, history_t *history)
{
    int index = 0;
    const char *cmd;

    if (strncmp(*line, "!", 1) != 0)
        return false;
    index = atoi(*line + 1);
    if (index <= 0 || index > history->history_count) {
        printf("Invalid history index\n");
        *line = NULL;
        return true;
    }
    cmd = history->command[index - 1];
    if (cmd == NULL) {
        printf("Invalid history index\n");
        *line = NULL;
        return true;
    }
    printf("%s\n", cmd);
    *line = cmd;
    return true;
}

static void process_command(char *line,
    command_fn_t f[COMMAND_COUNT], history_t *history)
{
    const char *resolved_line = line;

    while (resolve_history_command(&resolved_line, history))
        if (resolved_line == NULL)
            return;
    if (handle_builtin_command((char *)resolved_line, f, history))
        return;
    if (handle_library_command((char *)resolved_line))
        return;
    if (strlen(resolved_line) > 0)
        printf("Unknown command: %s\n", resolved_line);
}

void loop_command(command_fn_t f[COMMAND_COUNT], history_t *history)
{
    size_t len = 0;
    ssize_t read = 0;
    char *line = NULL;

    while (true) {
        write_color(1, BHRED, "obsidian");
        write(1, "> ", 3);
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        if (line[0] == '\n')
            continue;
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) > 0)
            history_add(line, history);
        process_command(line, f, history);
    }
    printf("\n");
    if (line)
        free(line);
}

int my_console(void)
{
    command_fn_t f[COMMAND_COUNT];
    history_t *history = NULL;

    memcpy(f, builtin_commands, sizeof(f));
    history = history_init();
    load_obsidianrc();
    loop_command(f, history);
    history_free(history);
    return 0;
}
