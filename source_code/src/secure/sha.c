/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-SEC-210-NCE-2-1-obsidian-2/source_code/secure
** File description:
** sha.c
*/

#include <openssl/evp.h>
#include <string.h>

void bytes_to_hex(const unsigned char *hash, unsigned int len, char **output)
{
    unsigned int i = 0;

    for (; i < len; i++)
        sprintf((*output) + (i * 2), "%02x", hash[i]);
    (*output)[len * 2] = '\0';
}

void compute_sha256_evp(const char *string, char **output_hex)
{
    EVP_MD_CTX *context = EVP_MD_CTX_new();
    unsigned char hash[EVP_MAX_MD_SIZE] = {0};
    unsigned int length_of_hash = 0;

    if (context == NULL)
        return;
    if (EVP_DigestInit_ex(context, EVP_sha256(), NULL)) {
        EVP_DigestUpdate(context, string, strlen(string));
        EVP_DigestFinal_ex(context, hash, &length_of_hash);
    }
    EVP_MD_CTX_free(context);
    bytes_to_hex(hash, length_of_hash, output_hex);
}

char *get_file_content(char *filename)
{
    FILE *fd = fopen(filename, "r");
    char *content = NULL;
    size_t len = 0;
    __ssize_t read = 0;

    if (!fd)
        return NULL;
    read = getline(&content, &len, fd);
    if (read > 0 && content[read - 1] == '\n')
        content[read - 1] = '\0';
    fclose(fd);
    return content;
}

int verify_hash(char *line)
{
    char *content = get_file_content("./src/secure/.shadow");
    char *result = malloc(sizeof(char) * 66);

    if (!content || !result)
        return 0;
    compute_sha256_evp(line, &result);
    if (!strcmp(content, result)) {
        free(result);
        free(content);
        return 1;
    }
    free(result);
    free(content);
    return 0;
}
