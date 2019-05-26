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
    if (arp_fill(arp, &args, \
                !(args.print_broadcast || args.print_spoof)) == false)
        return (84);
    if (args.print_broadcast == false && args.print_spoof == false)
        arp_spoof(arp);
    if (args.print_broadcast && arp_print_broadcast(arp))
        return (84);
    if (args.print_spoof && arp_print_spoof(arp) == false)
        return (84);
    return (0);
}