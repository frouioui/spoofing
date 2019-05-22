/*
** EPITECH PROJECT, 2019
** packet_receive
** File description:
** Receive an arp packet
*/

#include <stdlib.h>
#include <string.h>
#include <net/if_arp.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include "packet.h"

packet_t *packet_receive(int fd, char *src_packet)
{
    packet_t *packet_received = packet_init();
    char uint8_t_to_str[16] = {0};

    while (1) {
        if (recvfrom(fd, packet_received->buffer, 65535, 0, NULL, NULL) <= 0)
            return (NULL);
        if (ntohs(packet_received->content.ethernet.type) != ETH_P_ARP)
            continue;
        if (ntohs(packet_received->content.arp.opcode) != ARPOP_REPLY)
            continue;
        if ((packet_received->content.arp.sender_ip && !inet_ntop(AF_INET, \
            packet_received->content.arp.sender_ip, uint8_t_to_str, 16))
            || strcmp(uint8_t_to_str, src_packet)) {
            memset(uint8_t_to_str, 0, INET_ADDRSTRLEN);
            continue;
        }
        return (packet_received);
    }
    return (NULL);
}