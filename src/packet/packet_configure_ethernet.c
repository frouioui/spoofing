/*
** EPITECH PROJECT, 2019
** packet_configure_ethernet
** File description:
** Configure the ethernet header
*/

#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "packet.h"

bool packet_configure_ethernet(packet_t *packet, uint8_t *mac_src, \
                                uint8_t *mac_dest)
{
    if (packet == NULL)
        return (false);
    memcpy(packet->content.ethernet.dest_mac, mac_dest, MAC_ADDRESS_LENGTH);
    memcpy(packet->content.ethernet.src_mac, mac_src, MAC_ADDRESS_LENGTH);
    memcpy(&packet->content.ethernet.type, \
            (uint8_t[2]){0x0806 / 256, 0x0806 % 256}, sizeof(uint8_t) * 2);
    return (true);
}