/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** arp_print_spoof
*/

#include <string.h>
#include <stdlib.h>
#include "packet.h"
#include "arp.h"

bool arp_print_spoof(arp_t *arp)
{
    packet_t *packet = NULL;
    uint8_t *mac_spoofed = NULL;

    if (arp == NULL)
        return (false);
    packet = packet_init();
    if (packet == NULL)
        return (false);
    mac_spoofed = calloc(MAC_ADDRESS_LENGTH, sizeof(uint8_t));
    if (mac_spoofed == NULL)
        return (false);
    memcpy(mac_spoofed, arp->args->mac_address_spoof, 6);
    packet_configure_ethernet(packet, arp->src_mac_address, \
                            mac_spoofed);
    packet_configure_arp(packet, 1, mac_spoofed, arp);
    packet_print(packet);
    return (true);
}