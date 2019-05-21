/*
** EPITECH PROJECT, 2019
** arp_init
** File description:
** Initialize the structure arp
*/

#include <linux/if_packet.h>
#include <stdlib.h>
#include <string.h>
#include "arp.h"

arp_t *arp_init(void)
{
    arp_t *arp = malloc(sizeof(arp_t));

    if (arp == NULL)
        return (NULL);
    arp->interface_id = -1;
    arp->src_mac_address = NULL;
    arp->fd = -1;
    arp->address = calloc(1, sizeof(struct sockaddr_ll));
    arp->args = NULL;
    arp->sender_ip_address_str = NULL;
    arp->src_mac_address_str = NULL;
    arp->target_ip_address_str = NULL;
    return (arp);
}