/*
** EPITECH PROJECT, 2019
** ARP SPOOFING
** File description:
** Main file
*/

#include <stdlib.h>
#include <stdio.h>
#include "argument.h"
#include "errorsys.h"
#include "arp.h"

int main(const int argc, const char **argv)
{
    argument_t args = {0};
    error_t err = get_argument(&args, argc, argv);
    arp_t *arp = NULL;

    if (err.msg) {
        printf("Error: %s\n", err.msg);
        return (84);
    }
    arp = arp_init();
    if (arp_fill(arp, args.interface, args.src_ip, args.dest_ip) == false)
        return (84);
    return (0);
}