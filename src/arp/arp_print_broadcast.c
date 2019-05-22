/*
** EPITECH PROJECT, 2019
** arp_print_broadcast
** File description:
** Print the packet before sending it to broadcast
*/

#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <stdlib.h>
#include "arp.h"
#include "packet.h"

bool arp_print_broadcast(arp_t *arp)
{
    uint8_t broadcast_addr[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    packet_t *packet = NULL;

    if (arp == NULL)
        return (false);
    packet = packet_init();
    if (packet == NULL)
        return (false);
    packet_configure_ethernet(packet, arp->src_mac_address, broadcast_addr);
    packet_configure_arp(packet, 1, broadcast_addr, arp);
    packet_print(packet);
    return (true);
}