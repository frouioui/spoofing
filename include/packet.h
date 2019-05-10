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

#define MAC_ADDRESS_LENGTH 6
#define IP_ADDRESS_LENGTH 4

/**
* Arp header
* Hardware type -> Network link protocol type (Ethernet is 1)
* Protocol type -> 
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

bool packet_configure_ethernet(packet_t *packet, char *mac_src, char *mac_dest);
bool packet_configure_arp(packet_t *packet);

#endif /* !PACKET_H_ */
