/*
** EPITECH PROJECT, 2019
** arp_fill
** File description:
** Fill the stucture arp (socket, interface_id, mac_address)
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_ether.h>
#include "arp.h"

static bool arp_fill_socket(arp_t *arp)
{
    if (arp == NULL)
        return (false);
    arp->fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (arp->fd == -1) {
        printf("Error: failed to initialize the socket !\n");
        return (false);
    }
    return (true);
}

static bool arp_fill_interface_and_mac(arp_t *arp, char *interface)
{
    struct ifreq ifr;

    if (arp == NULL || interface == NULL)
        return (false);
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (ioctl(arp->fd, SIOCGIFINDEX, &ifr) == -1) {
        printf("Error: invalid interface.\n");
        return (false);
    }
    arp->interface_id = ifr.ifr_ifindex;
    if (ioctl(arp->fd, SIOCGIFHWADDR, &ifr) == -1) {
        printf("Error: unable to retrieve the mac address.\n");
        return (false);
    }
    arp->src_mac_address = calloc(7, sizeof(uint8_t));
    for (int i = 0; i < 6; i++)
        arp->src_mac_address[i] = ifr.ifr_hwaddr.sa_data[i];
    arp->src_mac_address[6] = '\0';
    return (true);
}

static bool arp_fill_target_and_sender(arp_t *arp, char *target_ip, \
                                        char *sender_ip)
{
    if (arp == NULL || target_ip == NULL || sender_ip == NULL)
        return (false);
    if (inet_pton(AF_INET, target_ip, arp->sender_ip_address) != 1)
        return (false);
    if (inet_pton(AF_INET, sender_ip, arp->target_ip_address) != 1)
        return (false);
    return (true);
}

static bool arp_fill(arp_t *arp, char *interface, char *target_ip, \
                    char *sender_ip)
{
    if (arp == NULL || interface == NULL)
        return (false);
    if (arp_fill_socket(arp) == false)
        return (false);
    if (arp_fill_interface_and_mac(arp, interface) == false)
        return (false);
    if (arp_fill_target_and_sender(arp, target_ip, sender_ip) == false)
        return (false);
    return (true);
}