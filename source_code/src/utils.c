/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/src
** File description:
** utils.c
*/

#include "ansi-colors.h"
#include <fcntl.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "obsidian.h"

void write_color(int fd, const char *color, const char *str)
{
    if (fd < 0 || !color || !str)
        return;
    dprintf(fd, "%s%s%s", color, str, CRESET);
}

static int cmd_matches(const char *cmd, const char *allowed)
{
    size_t len = strlen(allowed);

    if (strncmp(cmd, allowed, len) != 0)
        return 0;
    return (cmd[len] == '\0' || cmd[len] == ' ');
}

int is_allowed_exec(const char *cmd)
{
    const char *allowed_exec_cmds[] = {
        "ls",
        "echo",
        NULL
    };

    for (int i = 0; allowed_exec_cmds[i] != NULL; i++)
        if (cmd_matches(cmd, allowed_exec_cmds[i]))
            return 1;
    return 0;
}

static const char *get_home(void)
{
    const char *home = getenv("HOME");
    struct passwd *pw = NULL;

    if (home != NULL)
        return home;
    pw = getpwuid(getuid());
    if (pw != NULL)
        return pw->pw_dir;
    return NULL;
}

static int build_rc_path(char *path, char *resolved)
{
    const char *home = get_home();
    int written = 0;

    if (home == NULL)
        return -1;
    written = snprintf(path, PATH_MAX, "%s/.obsidianrc", home);
    if (written < 0 || written >= PATH_MAX)
        return -1;
    if (realpath(path, resolved) == NULL)
        return -1;
    if (strncmp(resolved, home, strlen(home)) != 0)
        return -1;
    return 0;
}

static FILE *open_obsidianrc(void)
{
    char path[PATH_MAX];
    char resolved[PATH_MAX];

    if (build_rc_path(path, resolved) < 0)
        return NULL;
    return fopen(resolved, "r");
}

static void print_obsidian_command(const char *line)
{
    printf("Obsidian command: %s\n", line);
}

static void run_child(char **argv)
{
    execvp(argv[0], argv);
    dprintf(STDERR_FILENO, "obsidianrc: exec failed: %s\n", argv[0]);
    _exit(127);
}

static void fork_cmd(char **argv)
{
    pid_t pid = fork();

    if (pid < 0) {
        dprintf(STDERR_FILENO, "obsidianrc: fork failed\n");
        return;
    }
    if (pid == 0)
        run_child(argv);
    waitpid(pid, NULL, 0);
}

static int split_cmd(char *buf, char **argv)
{
    int argc = 0;
    char *tok = strtok(buf, " \t");

    while (tok != NULL && argc < 63) {
        argv[argc] = tok;
        argc++;
        tok = strtok(NULL, " \t");
    }
    argv[argc] = NULL;
    return argc;
}

static void exec_allowed_cmd(const char *cmd)
{
    char buf[1024];
    char *argv[64];
    int written = snprintf(buf, sizeof(buf), "%s", cmd);

    if (written < 0 || written >= (int)sizeof(buf))
        return;
    if (split_cmd(buf, argv) == 0)
        return;
    fork_cmd(argv);
}

static void handle_exec_line(const char *line)
{
    char cmd[1024] = {0};

    snprintf(cmd, sizeof(cmd), "%s", line + 5);
    if (!is_allowed_exec(cmd)) {
        dprintf(STDERR_FILENO, "obsidianrc: blocked exec: %s\n", cmd);
        return;
    }
    exec_allowed_cmd(cmd);
}

static void process_line(const char *line)
{
    if (line[0] == '#' || line[0] == '\0')
        return;
    if (strncmp(line, "exec ", 5) == 0) {
        handle_exec_line(line);
        return;
    }
    print_obsidian_command(line);
}

void load_obsidianrc(void)
{
    FILE *rc_file = open_obsidianrc();
    char line[1024] = {0};

    if (rc_file == NULL)
        return;
    while (fgets(line, sizeof(line), rc_file)) {
        line[strcspn(line, "\n")] = '\0';
        process_line(line);
    }
    fclose(rc_file);
}
