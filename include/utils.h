/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stdint.h>

void print_mac_address(uint8_t *mac);
void print_ip_address(uint8_t *ip);
char **my_str_split(char *str, char *delim);

#endif /* !UTILS_H_ */
