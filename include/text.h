/*
** EPITECH PROJECT, 2018
** stumper
** File description:
** text.h
*/

#ifndef TEXT_H_
#define TEXT_H_

#include "my.h"

typedef struct stumper_s {
	int group;
	int tri;
	char *chars;
	int *nb;
	char *to_find;
	char *str;
} stumper_t;

stumper_t *detect_params(int ac, char **av);
void algo1(stumper_t *stumper);
void algo2(stumper_t *stumper);
void tri(stumper_t *stumper);
void free_stumper(stumper_t *stumper);

#endif
