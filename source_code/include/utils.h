/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/include
** File description:
** utils.h
*/

#ifndef UTILS_H
    #define UTILS_H

void write_color(int fd, const char *color, const char *str);
void load_obsidianrc(void);
void bytes_to_hex(const unsigned char *hash, unsigned int len, char **output);
void compute_sha256_evp(const char *string, char **output_hex);
char *get_file_content(char *filename);
int verify_hash(char *line);
int is_allowed_exec(const char *cmd);

#endif /* UTILS_H */
