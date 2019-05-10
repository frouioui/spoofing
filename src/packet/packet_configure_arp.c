/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** packet_configure_arp
*/

#include <stdlib.h>
#include <string.h>
#include "packet.h"
#include "arp.h"

bool packet_configure_arp(packet_t *packet, int opcode, uint8_t *dest_mac,\
                         arp_t *arp)
{
    if (packet == NULL)
        return (false);
    packet->content.arp.hardware_type = htons(1);
    packet->content.arp.protocol_type = htons(0x0800); // ETH_P_IP
    packet->content.arp.hardware_len = MAC_ADDRESS_LENGTH;
    packet->content.arp.protocol_len = IP_ADDRESS_LENGTH;
    packet->content.arp.opcode = htons(opcode); // 1 for ARP request and 2 for ARP reply
    memcpy(packet->content.arp.sender_mac, arp->src_mac_address, \
            sizeof(uint8_t) * MAC_ADDRESS_LENGTH);
    memcpy(packet->content.arp.target_mac, dest_mac, \
            sizeof(uint8_t) * MAC_ADDRESS_LENGTH);
    memcpy(packet->content.arp.sender_ip, arp->sender_ip_address, \
            sizeof(uint8_t) * IP_ADDRESS_LENGTH);
    memcpy(packet->content.arp.target_ip, arp->target_ip_address, \
            sizeof(uint8_t) * IP_ADDRESS_LENGTH);
    return (true);
}
