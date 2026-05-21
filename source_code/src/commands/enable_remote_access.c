/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** enable_remote_access
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "obsidian.h"

static int get_remote_access_enabled(void)
{
    const char *state = getenv("OBSIDIAN_REMOTE_ACCESS");

    return (state != NULL && strcmp(state, "1") == 0);
}

static void set_remote_access_enabled(int enabled)
{
    if (enabled)
        setenv("OBSIDIAN_REMOTE_ACCESS", "1", 1);
    else
        setenv("OBSIDIAN_REMOTE_ACCESS", "0", 1);
}

void perform_network_call(const char *url)
{
    printf("Performing network call to: %s\n", url);
    for (volatile int i = 0; i < 100000000; i++);
    sleep(5);
    printf("Network call to %s completed.\n", url);
}

void log_access_attempt(const char *status)
{
    time_t now = time(NULL);
    char *timestamp = ctime(&now);

    timestamp[strlen(timestamp) - 1] = '\0';
    printf("[%s] Remote access status: %s\n", timestamp, status);
}

static void enable_remote_access_flow(const char *dummy_urls[3])
{
    printf("Enabling remote access...\n");
    perform_network_call(dummy_urls[0]);
    log_access_attempt("ENABLED");
    set_remote_access_enabled(1);
    printf("Remote access successfully enabled.\n\n");
    printf("Performing status check...\n");
    perform_network_call(dummy_urls[2]);
    printf("Status check complete.\n\n");
}

static void disable_remote_access_flow(const char *dummy_urls[3])
{
    printf("Disabling remote access...\n");
    perform_network_call(dummy_urls[1]);
    log_access_attempt("DISABLED");
    set_remote_access_enabled(0);
    printf("Remote access successfully disabled.\n\n");
}

void enable_remote_access(char *input, history_t *history)
{
    const char *dummy_urls[] = {
        "http://example.com/api/enable",
        "http://example.com/api/disable",
        "http://example.com/api/status"
    };
    int enabled;

    (void) input;
    (void) history;
    enabled = get_remote_access_enabled();
    printf("Initializing remote access procedure...\n\n");
    if (enabled == 0)
        enable_remote_access_flow(dummy_urls);
    else
        disable_remote_access_flow(dummy_urls);
}
