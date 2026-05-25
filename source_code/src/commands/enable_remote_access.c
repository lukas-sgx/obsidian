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
#include <fcntl.h>
#include "obsidian.h"

static int get_remote_access_enabled(void)
{
    FILE *f = fopen(ACCESS_STATE_FILE, "r");
    int state = 0;

    if (f == NULL)
        return 0;
    fscanf(f, "%d", &state);
    fclose(f);
    return (state == 1);
}

static int set_remote_access_enabled(int enabled)
{
    int fd = open(ACCESS_STATE_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    struct flock lock = {0};

    if (fd < 0) {
        perror("Failed to open state file");
        return -1;
    }
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("Failed to lock state file");
        close(fd);
        return -1;
    }
    dprintf(fd, "%d\n", enabled ? 1 : 0);
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);
    return 0;
}

void perform_network_call(const char *url)
{
    printf("Performing network call to: %s\n", url);
    printf("Network call to %s completed.\n", url);
}

void log_access_attempt(const char *status)
{
    time_t now = time(NULL);
    char timestamp[26];

    ctime_r(&now, timestamp);
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
        "https://example.com/api/enable",
        "https://example.com/api/disable",
        "https://example.com/api/status"
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
