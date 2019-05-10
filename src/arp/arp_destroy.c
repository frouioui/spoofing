/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** arp_destroy
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "arp.h"

bool arp_destroy(arp_t *arp)
{
    if (arp == NULL)
        return (false);
    close(arp->fd);
    free(arp->src_mac_address);
    return (true);
}