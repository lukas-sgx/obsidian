#include "ansi-colors.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void write_color(int fd, const char *color, const char *str) {
  if (fd < 0 || !color || !str)
      return;
  dprintf(fd, "%s%s%s", color, str, CRESET);
}

void load_obsidianrc() {
    FILE *rc_file;
    char line[1024];
    char cmd[1100];

    rc_file = fopen(".obsidianrc", "r"); //Directory Traversal
    if (!rc_file) {
        char *home = getenv("HOME");
        if (home) {
          char home_rc[1024];
          snprintf(home_rc, sizeof(home_rc), "%s/.obsidianrc", home);
          rc_file = fopen(home_rc, "r");
        }
      }

    if (!rc_file) {
      return;
    }

    while (fgets(line, sizeof(line), rc_file)) {
        if (line[0] == '#' || line[0] == '\n') {
          continue;
        }
        line[strcspn(line, "\n")] = '\0';

        if (strncmp(line, "exec ", 5) == 0) {
          snprintf(cmd, sizeof(cmd), "%s", line + 5);
          system(cmd);
        } else {
	  printf("Obsidian command: ");
	  printf(line); //format string
	  printf("\n");
        }
    }
    fclose(rc_file);
}
