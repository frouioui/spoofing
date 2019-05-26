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
    uint8_t *src_mac_address;
    uint8_t *sender_ip_address;
    uint8_t *target_ip_address;
    int interface_id;
    struct sockaddr_ll *address;
    argument_t *args;
} arp_t;

arp_t *arp_init(void);
bool arp_fill(arp_t *arp, argument_t *args, bool is_sudo);
bool arp_spoof(arp_t *arp);
bool arp_destroy(arp_t *arp);
bool arp_print_broadcast(arp_t *arp);
bool arp_print_spoof(arp_t *arp);

#endif /* !ARP_H_ */
