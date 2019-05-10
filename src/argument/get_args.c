/*
** EPITECH PROJECT, 2019
** ARP SPOOFING
** File description:
** Get the argument from argc/argv and return an arg struct
*/

#include <stdlib.h>
#include <string.h>
#include "errorsys.h"
#include "argument.h"

static bool is_nb_args_valid(const int argc)
{
    return (argc >= 4 && argc <= 6);
}

static void get_params(argument_t *args, const char **argv)
{
    args->src_ip = strdup(argv[1]);
    args->dest_ip = strdup(argv[2]);
    args->interface = strdup(argv[3]);

}

static error_t get_flag_broadcast(argument_t *args, const char *flag)
{
    error_t nerr = {0};

    if (strcmp("--printBroadcast", flag) != 0)
        return (create_error("The broadcast flag must be '--printBroadcast'"));
    args->print_broadcast = true;
    return (nerr);
}

static error_t get_flag_spoof(argument_t *args, const char *flag,
    const char *value)
{
    error_t nerr = {0};

    if (strcmp("--printSpoof", flag) != 0)
        return (create_error("The spoof flag must be '--printSpoof'"));
    args->print_spoof = true;
    args->mac_address_spoof = strdup(value);
    return (nerr);
}

error_t get_argument(argument_t *args, const int argc, const char **argv)
{
    error_t err = {0};

    if (is_nb_args_valid(argc) == false)
        return (create_error("Invalid number of argument"));
    get_params(args, argv);
    if (argc == 5)
        err = get_flag_broadcast(args, argv[4]);
    else if (argc == 6)
        err = get_flag_spoof(args, argv[4], argv[5]);
    return (err);
}