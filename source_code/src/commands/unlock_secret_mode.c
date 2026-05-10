/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** unlock_secret_mode
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "obsidian.h"

void unlock_secret_mode()
{
    if (IS_ADMIN) { // admin via activate_emergency_protocols -> admin123
        printf("Secret mode unlocked! Welcome, admin.\n");
        printf("{ADMIN4242}\n");
    } else {
        printf("Access denied. You do not have the required privileges.\n");
    }
}
