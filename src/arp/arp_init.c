/*
** EPITECH PROJECT, 2019
** arp_init
** File description:
** Initialize the structure arp
*/

#include <stdlib.h>
#include "arp.h"

arp_t *arp_init(void)
{
    arp_t *arp = malloc(sizeof(arp_t));

    if (arp == NULL)
        return (NULL);
    arp->interface_id = -1;
    arp->mac_address = NULL;
    arp->fd = -1;
    return (arp);
}