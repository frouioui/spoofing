/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** packet_configure_ethernet
*/

#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "packet.h"

bool packet_configure_ethernet(packet_t *packet, char *mac_src, char *mac_dest)
{
    if (packet == NULL)
        return (false);
    if (mac_src || mac_dest)
        return (true);
    // packet->content.ethernet.dest_mac = strdup(mac_dest);
    return (true);
}