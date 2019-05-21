/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** packet
*/

#ifndef PACKET_H_
#define PACKET_H_

#include <stdbool.h>
#include <stdint.h>
#include "arp.h"

#define MAC_ADDRESS_LENGTH 6
#define IP_ADDRESS_LENGTH 4

/**
* Arp header
*/
typedef struct arp_header_s {
    uint16_t hardware_type;
    uint16_t protocol_type;
    uint8_t hardware_len;
    uint8_t protocol_len;
    uint16_t opcode;
    uint8_t sender_mac[MAC_ADDRESS_LENGTH];
    uint8_t sender_ip[IP_ADDRESS_LENGTH];
    uint8_t target_mac[MAC_ADDRESS_LENGTH];
    uint8_t target_ip[IP_ADDRESS_LENGTH];
} arp_header_t;

/**
* Ethernet header
*/
typedef struct ethernet_header_s
{
    uint8_t dest_mac[MAC_ADDRESS_LENGTH];
    uint8_t src_mac[MAC_ADDRESS_LENGTH];
    uint16_t type;
} ethernet_header_t;

typedef struct packet_content_s
{
    ethernet_header_t ethernet;
    arp_header_t arp;
} packet_content_t;

typedef union packet_s {
    char buffer[1024];
    packet_content_t content;
} packet_t;

packet_t *packet_init(void);
bool packet_configure_ethernet(packet_t *packet, uint8_t *mac_src, \
                                uint8_t *mac_dest);
bool packet_configure_arp(packet_t *packet, int opcode, uint8_t *dest_mac, \
                            arp_t *arp);
bool packet_send(int fd, packet_t *packet, struct sockaddr *address, \
                socklen_t addr_len);
packet_t *packet_receive(int fd, char *src_packet);
bool packet_print(packet_t *packet);

#endif /* !PACKET_H_ */
