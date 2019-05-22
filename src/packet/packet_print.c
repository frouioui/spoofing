/*
** EPITECH PROJECT, 2019
** packet_print
** File description:
** Print the packet
*/

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include "packet.h"
#include "utils.h"

static bool print_ethernet_header(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    for (int i = 0; i < MAC_ADDRESS_LENGTH; i++)
        printf("%02x ", packet->content.ethernet.dest_mac[i]);
    for (int i = 0; i < MAC_ADDRESS_LENGTH; i++)
        printf("%02x ", packet->content.ethernet.src_mac[i]);
    printf("08 06 ");
    return (true);
}

static bool print_arp_header_mac(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    for (int i = 0; i < IP_ADDRESS_LENGTH; i++) {
        if (i == IP_ADDRESS_LENGTH - 1)
            printf("%02x", packet->content.arp.target_ip[i]);
        else
            printf("%02x ", packet->content.arp.target_ip[i]);
    }
    return (true);
}

static bool print_arp_header(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    printf("00 01 ");
    printf("08 00 ");
    printf("06 ");
    printf("04 ");
    printf("00 0");
    if (packet->content.arp.opcode == 256)
        printf("1 ");
    else
        printf("2 ");
    for (int i = 0; i < MAC_ADDRESS_LENGTH; i++)
        printf("%02x ", packet->content.arp.sender_mac[i]);
    for (int i = 0; i < IP_ADDRESS_LENGTH; i++)
        printf("%02x ", packet->content.arp.sender_ip[i]);
    for (int i = 0; i < MAC_ADDRESS_LENGTH; i++)
        printf("%02x ", packet->content.arp.target_mac[i]);
    print_arp_header_mac(packet);
    return (true);
}

bool packet_print(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    print_ethernet_header(packet);
    print_arp_header(packet);
    printf("\n");
    return (true);
}