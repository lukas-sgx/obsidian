#ifndef HISTORY_H
#define HISTORY_H

#define MAX_COMMAND_LENGTH 256

void history_init(void);
void history_add(const char *command);
void history_clear(void);
void history_free(void);
void history_show(void);
const char *history_get(int index);
int history_count_get(void);

#endif /* HISTORY_H */