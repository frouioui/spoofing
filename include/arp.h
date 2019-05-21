/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** arp
*/

#ifndef ARP_H_
#define ARP_H_

#include <stdint.h>
#include <stdbool.h>
#include <linux/if.h>
#include "argument.h"

typedef struct arp_s
{
    int fd;
    char *src_mac_address_str;
    uint8_t *src_mac_address;
    uint8_t *sender_ip_address;
    uint8_t *sender_ip_address_str;
    uint8_t *target_ip_address;
    uint8_t *target_ip_address_str;
    int interface_id;
    struct sockaddr_ll *address;
    argument_t *args;
} arp_t;

arp_t *arp_init(void);
bool arp_fill(arp_t *arp, argument_t *args, bool isSudo);
bool arp_spoof(arp_t *arp);
bool arp_destroy(arp_t *arp);
bool arp_print_broadcast(arp_t *arp);
bool arp_print_spoof(arp_t *arp);

#endif /* !ARP_H_ */
