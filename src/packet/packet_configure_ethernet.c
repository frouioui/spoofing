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

bool packet_configure_ethernet(packet_t *packet, uint8_t *mac_src, \
                                uint8_t *mac_dest)
{
    if (packet == NULL)
        return (false);
    memcpy(packet->content.ethernet.dest_mac, mac_dest, MAC_ADDRESS_LENGTH);
    memcpy(packet->content.ethernet.src_mac, mac_src, MAC_ADDRESS_LENGTH);
    packet->content.ethernet.type = 0x0806;//(uint8_t[2]){ETH_P_ARP / 256, ETH_P_ARP % 256};
    return (true);
}