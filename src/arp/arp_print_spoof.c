/*
** EPITECH PROJECT, 2019
** arp_print_spoof
** File description:
** Print the packet before sending it to the target
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "packet.h"
#include "arp.h"
#include "utils.h"

static bool fill_mac_address_spoofed(uint8_t *mac_spoofed, arp_t *arp)
{
    char **mac_split = my_str_split(arp->args->mac_address_spoof, ":");
    size_t size = 0;

    if (mac_split == NULL)
        return (false);
    while (mac_split[size])
        size++;
    if (size != MAC_ADDRESS_LENGTH)
        return (false);
    mac_spoofed[0] = strtol(mac_split[0], NULL, 16);
    mac_spoofed[1] = strtol(mac_split[1], NULL, 16);
    mac_spoofed[2] = strtol(mac_split[2], NULL, 16);
    mac_spoofed[3] = strtol(mac_split[3], NULL, 16);
    mac_spoofed[4] = strtol(mac_split[4], NULL, 16);
    mac_spoofed[5] = strtol(mac_split[5], NULL, 16);
    return (true);
}

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
    if (fill_mac_address_spoofed(mac_spoofed, arp) == false)
        return (false);
    packet_configure_ethernet(packet, arp->src_mac_address, \
                            mac_spoofed);
    packet_configure_arp(packet, 2, mac_spoofed, arp);
    packet_print(packet);
    return (true);
}