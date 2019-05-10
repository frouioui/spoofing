/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** arp
*/

#ifndef ARP_H_
#define ARP_H_

#include <stdbool.h>

typedef struct arp_s
{
    int fd;
    char *mac_address;
    int interface_id;
} arp_t;

arp_t *arp_init(void);
bool arp_fill(arp_t *arp, char *interface);
bool arp_destroy(arp_t *arp);
#endif /* !ARP_H_ */
