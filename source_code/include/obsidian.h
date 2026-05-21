/*
** EPITECH PROJECT, 2025
** obsidian
** File description:
** header for obsidian
*/

#ifndef OBSIDIAN_H_
    #define OBSIDIAN_H_

    #include "history.h"
    #include <stdbool.h>

typedef void (*command_fn_t)(char *input, history_t *history);

int my_console(void);

void init_reactor(char *input, history_t *history);
void check_reactor_status(char *input, history_t *history);
void activate_emergency_protocols(char *input, history_t *history);
void simulate_meltdown(char *input, history_t *history);
void check_cooling_pressure(char *input, history_t *history);
void send_status_report(char *input, history_t *history);
void monitor_radiation_levels(char *input, history_t *history);
void set_reactor_power(char *input, history_t *history);
void run_diagnostic(char *input, history_t *history);
void enable_remote_access(char *input, history_t *history);
void check_cooling_pressure(char *input, history_t *history);
void quit(char *input, history_t *history);
void help(char *input, history_t *history);
void load_fuel_rods(char *input, history_t *history);
void log_system_event(char *input, history_t *history);
void unlock_secret_mode(char *input, history_t *history);
void load_config(char *input, history_t *history);
void show_history(char *input, history_t *history);
void configure_cooling_system(char *input, history_t *history);
void trigger_emergency_shutdown(char *input, history_t *history);
void init_labo(char *input, history_t *history);
void init_workers(char *input, history_t *history);
void call_api(char *input, history_t *history);
void alchemy(char *input, history_t *history);

enum commands {
    INIT_REACTOR,
    CHECK_REACTOR_STATUS,
    ACTIVATE_EMERGENCY_PROTOCOLS,
    SIMULATE_MELTDOWN,
    CHECK_COOLING_PRESSURE,
    SEND_STATUS_REPORT,
    MONITOR_RADIATION_LEVELS,
    SET_REACTOR_POWER,
    RUN_DIAGNOSTIC,
    ENABLE_REMOTE_ACCESS,
    QUIT,
    HELP,
    LOAD_FUEL_RODS,
    LOG_SYSTEM_EVENT,
    UNLOCK_SECRET_MODE,
    LOAD_CONFIG,
    HISTORY,
    CONFIGURE_COOLING_SYSTEM,
    TRIGGER_EMERGENCY_SHUTDOWN,
    INIT_LABO,
    INIT_WORKERS,
    CALL_API,
    ALCHEMY,
    COMMAND_COUNT,
};

enum commands_lib {
    INIT_STEAM_TURBINE,
    READ_TURBINE_CONFIG,
    TURINE_REMOTE_ACCESS,
    RUN_TURBINE,
    TURBINE_TEMPERATURE,
    COMMAND_COUNT_LIB,
};

typedef struct base64_context_s {
    const char *chars;
    char *output;
    int index;
} base64_context_t;

#endif /* !OBSIDIAN_H_ */
