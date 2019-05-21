/*
** EPITECH PROJECT, 2019
** ARP SPOOFING
** File description:
** Main file of the arguments parsing features
*/

#if !defined(_ARGUMENT_H)
#define _ARGUMENT_H

#include <stdbool.h>
#include "errorsys.h"

struct argument_s {
    char *src_ip;
    char *dest_ip;
    char *interface;
    bool print_broadcast;
    bool print_spoof;
    char *mac_address_spoof;
};

typedef struct argument_s argument_t;

error_t get_argument(argument_t *args, const int argc, const char **argv);

#endif // _ARGUMENT_H
