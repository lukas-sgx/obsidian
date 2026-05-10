/*
** EPITECH PROJECT, 2025
** obsidian
** File description:
** header for obsidian
*/

#ifndef OBSIDIAN_H_
#define OBSIDIAN_H_

#include <stdbool.h>

extern bool IS_ADMIN;
#define UNUSED __attribute__((unused))

int my_console(void);

void init_reactor();
void check_reactor_status();
void activate_emergency_protocols();
void simulate_meltdown();
void check_cooling_pressure();
void send_status_report();
void monitor_radiation_levels();
void set_reactor_power();
void run_diagnostic();
void enable_remote_access();
void check_cooling_pressure();
void quit();
void help();
void load_fuel_rods();
void log_system_event();
void unlock_secret_mode();
void load_config();
void show_history(char *input);
void configure_cooling_system();
void trigger_emergency_shutdown();
void init_labo();
void init_workers();
void call_api();
void alchemy();

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
extern const char *command_strings[];

enum commands_lib {
    INIT_STEAM_TURBINE,
    READ_TURBINE_CONFIG,
    TURINE_REMOTE_ACCESS,
    RUN_TURBINE,
    TURBINE_TEMPERATURE,
    COMMAND_COUNT_LIB,
};

#endif /* !OBSIDIAN_H_ */
