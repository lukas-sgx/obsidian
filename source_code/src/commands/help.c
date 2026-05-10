/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** help
*/

#include <stdio.h>
#include <string.h>

void help()
{
    const char *commands[] = {
        "- init_reactor: Initialize the reactor for operation.",
        "- check_reactor_status: Check the current status of the reactor.",
        "- activate_emergency_protocols: Activate emergency protocols (requires admin).",
        "- simulate_meltdown: Simulate a reactor meltdown for testing purposes.",
        "- check_cooling_pressure: Check the pressure in the cooling system.",
        "- send_status_report: Send a status report to the control center.",
        "- monitor_radiation_levels: Monitor radiation levels in the reactor.",
        "- set_reactor_power: Adjust the reactor's power output.",
        "- run_diagnostic: Run a full diagnostic on the reactor systems.",
        "- enable_remote_access: Enable or disable remote access to the reactor.",
        "- quit: Exit the console.",
        "- help: Display this help message.",
        "- load_fuel_rods: Load fuel rods into the reactor.",
        "- log_system_event: Log a system event.",
        "- history: Display command history.",
        "- !n: Execute command number n from history."
        "- load_config: Load configuration from a file.",
        "- configure_cooling_system: Configure the cooling system.",
        "---- External libraries ----",
        "- init_steam_turbine: Initialize the turbine.",
        "- read_turbine_config: Read the turbine configuration.",
        "- run_turbine: Run the turbine.",
        "- turbine_temperature: Change the turbine temperature.",
        "- turbine_remote_access: Remote access to the turbine.",
        "---- Static libraries ----",
        "- alchemy: Perform alchemy operations.",
        "- call_api: Call an external API.",
        "- init_labo: Initialize the laboratory.",
        "- init_workers: Initialize workers for reactor operations.",
    };
    int command_count = sizeof(commands) / sizeof(commands[0]);

    printf("Available commands :\n");
    for (int i = 0; i < command_count; i++) {
        printf("%s\n", commands[i]);
    }
    printf("\n");
    printf("Configuration:\n");
    printf("- .obsidianrc: Create this file in your home directory or current directory\n");
    printf("  to automatically execute commands at startup.\n");
    printf("  Use 'exec <command>' to execute shell commands.\n");
    printf("\n");
}