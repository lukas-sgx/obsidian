/*
** EPITECH PROJECT, 2024
** Obsidian
** File description:
** monitor_radiation_levels
*/

#include <stdio.h>
#include <string.h>
void secret_function ()
	{
		printf (
				"{The stone isn't in the pocket anymore ...}\n"); // Flag
	}
void monitor_radiation_levels ()
	{
		char    buffer[10]; // Stack-Based Buffer Overflow -> segfault
		void (* function_ptr) () = NULL;
		printf ("Enter radiation levels: ");
		gets (buffer);
		printf ("Radiation Levels: %s\n" ,buffer);
		if (function_ptr)
			{
				function_ptr(); // Memory corrucption
			} else
			{
				printf ("Function Pointer: %p\n"
						,( void * ) function_ptr);
			}
	}
