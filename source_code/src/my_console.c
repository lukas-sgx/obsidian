/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** my_console
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

bool IS_ADMIN = false;

const char *command_strings[] = {
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

static void initialize_commands(void (*f[COMMAND_COUNT])(char *input))
{
    f[INIT_REACTOR] = init_reactor;
    f[CHECK_REACTOR_STATUS] = check_reactor_status;
    f[ACTIVATE_EMERGENCY_PROTOCOLS] = activate_emergency_protocols;
    f[SIMULATE_MELTDOWN] = simulate_meltdown;
    f[CHECK_COOLING_PRESSURE] = check_cooling_pressure;
    f[SEND_STATUS_REPORT] = send_status_report;
    f[MONITOR_RADIATION_LEVELS] = monitor_radiation_levels;
    f[SET_REACTOR_POWER] = set_reactor_power;
    f[RUN_DIAGNOSTIC] = run_diagnostic;
    f[ENABLE_REMOTE_ACCESS] = enable_remote_access;
    f[QUIT] = quit;
    f[HELP] = help;
    f[LOAD_FUEL_RODS] = load_fuel_rods;
    f[LOG_SYSTEM_EVENT] = log_system_event;
    f[UNLOCK_SECRET_MODE] = unlock_secret_mode;
    f[LOAD_CONFIG] = load_config;
    f[HISTORY] = show_history;
    f[CONFIGURE_COOLING_SYSTEM] = configure_cooling_system;
    f[TRIGGER_EMERGENCY_SHUTDOWN] = trigger_emergency_shutdown;
    f[INIT_LABO] = init_labo;
    f[INIT_WORKERS] = init_workers;
    f[ALCHEMY] = alchemy;
    f[CALL_API] = call_api;
}

const char *command_strings_lib[] = {
    "init_steam_turbine",
    "read_turbine_config",
    "turbine_remote_access",
    "turbine_temperature",
    "run_turbine",
};

void check_pepito_lib(char *input){
    typedef void(*t_myfunc)(void);

    void* dlh = dlopen("obsidian_lib.so", RTLD_LAZY);
    if (dlh == NULL) { 
        fprintf(stderr, "%s\n", dlerror()); 
        exit(1); 
    }
    void (*fnc)() = dlsym(dlh, input);
    if (fnc == NULL) { 
        fprintf(stderr, "%s\n", dlerror()); 
        exit(1); 
    }
    fnc();
}

static void process_command(char *line, void (*f[COMMAND_COUNT])(char *input))
{
    bool command_found = false;

    for (int i = 0; i < COMMAND_COUNT; i++) {
        if (strcmp(line, command_strings[i]) == 0) {
            f[i](line);
            command_found = true;
            break;
        }
    }
    for (int i = 0; i < COMMAND_COUNT_LIB; i++) {
        if (strcmp(line, command_strings_lib[i]) == 0) {
            check_pepito_lib(line);
            command_found = true;
            break;
        }
    }

    if (strncmp(line, "!", 1) == 0) {
        int index = atoi(line + 1);
        if (index > 0 && index <= history_count_get()) {
            const char *cmd = history_get(index - 1);
            if (cmd) {
                printf("%s\n", cmd);
                process_command((char *)cmd, f);
                command_found = true;
            }
        } else {
            printf("Invalid history index\n");
            command_found = true;
        }
    }
    
    if (!command_found && strlen(line) > 0) {
        printf("Unknown command: %s\n", line);
    }
}

void show_history(char *input)
{
    (void)input;
    history_show();
}

int my_console(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    void (*f[COMMAND_COUNT])(char *input);

    initialize_commands(f);
    history_init();
    load_obsidianrc();

    while (1) {
        write_color(1, BHRED, "obsidian");
        write(1, "> ", 3);
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        if (line[0] == '\n')
            continue;

        line[strcspn(line, "\n")] = '\0';
        
        if (strlen(line) > 0)
            history_add(line);
            
        process_command(line, f);
    }

    history_free();
    free(line);
    return 0;
}
